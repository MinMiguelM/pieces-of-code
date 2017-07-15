mongod --replSet m101 --logpath "1.log" --dbpath /home/miguel/data/rs1 --port 27017 --smallfiles --oplogSize 64 --fork
mongod --replSet m101 --logpath "2.log" --dbpath /home/miguel/data/rs2 --port 27018 --smallfiles --oplogSize 64 --fork
mongod --replSet m101 --logpath "3.log" --dbpath /home/miguel/data/rs3 --port 27019 --smallfiles --oplogSize 64 --fork

db.messages.find({
	"headers.From":"andrew.fastow@enron.com",
	"headers.To":"jeff.skilling@enron.com"
}).count();

db.messages.aggregate([
	{
		$unwind:"$headers.To"
	},{
		$group:{
			_id:{"id":"$_id","from":"$headers.From"},
			to:{$addToSet:"$headers.To"}
		}
	},{
		$unwind:"$to"
	},{
		$group:{
			_id:{"from":"$_id.from","to":"$to"},
			count:{$sum:1}
		}
	},{
		$sort:{"count":-1}
	}
]);

db.messages.update(
	{"headers.Message-ID":"<8147308.1075851042335.JavaMail.evans@thyme>"},
	{$push:{"headers.To":"mrpotatohead@mongodb.com"}}
);