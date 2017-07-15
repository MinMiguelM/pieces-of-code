import pymongo

# establish a connection to the database
connection = pymongo.MongoClient("mongodb://localhost")

# get a handle to the test database
db=connection.test
albums = db.albums
images = db.images

listToRemove = []

for i in images.find():
	id = i['_id']
	exist = albums.find({'images':id})
	if exist.count() == 0:
		listToRemove.append(id);

print(len(listToRemove))

for i in listToRemove:
	images.delete_one({'_id':i})