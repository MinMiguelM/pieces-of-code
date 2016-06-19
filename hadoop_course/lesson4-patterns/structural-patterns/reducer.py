#!/usr/bin/python

import sys

index = []
actualKey = None
reputation = None
gold = None
silver = None
bronze = None

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    thisKey = data_mapped[0].replace("\"","")
    thisFile = data_mapped[1].replace("\"","")

    if thisFile == "A":
        actualKey = thisKey
        reputation = data_mapped[2]
        gold = data_mapped[3]
        silver = data_mapped[4]
        bronze = data_mapped[5]
    if thisFile == "B" and thisKey == actualKey:
        print data_mapped[2],"\t",data_mapped[3],"\t",data_mapped[4],"\t",data_mapped[5],"\t",data_mapped[6],"\t",data_mapped[7],"\t",data_mapped[8],"\t",data_mapped[9],"\t",reputation,"\t",gold,"\t",silver,"\t",bronze
