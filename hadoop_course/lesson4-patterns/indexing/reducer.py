#!/usr/bin/python

import sys

count = 0
oldKey = None
index = []

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisNode = data_mapped

    if oldKey and oldKey != thisKey:
        print oldKey, "\t", count, "\t",index
        oldKey = thisKey;
        count = 0
        index = []

    oldKey = thisKey
    count += 1
    if index.count(thisNode) == 0:
        index.append(thisNode)

if oldKey != None:
    print oldKey, "\t", count, "\t",index

