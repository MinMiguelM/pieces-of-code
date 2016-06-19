#!/usr/bin/python

import sys

count = 0
priceTotal = 0
oldKey = None

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisNode = data_mapped

    if oldKey and oldKey != thisKey:
        average = float(priceTotal)/float(count)
        print oldKey, "\t",average
        oldKey = thisKey;
        count = 0
        priceTotal = 0

    oldKey = thisKey
    count += 1
    priceTotal += float(thisNode)

if oldKey != None:
    average = float(priceTotal)/float(count)
    print oldKey, "\t",average

