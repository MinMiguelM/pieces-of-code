#!/usr/bin/python

import sys

oldKey = None
oldLen = None
count = 0
totalLength = 0

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 3:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisNode, thisLen = data_mapped

    if oldKey and oldKey != thisKey:
        if count > 0:
            print oldKey,'\t',oldLen,'\t',float(totalLength/count)
        else:
            print oldKey,'\t',oldLen,'\t',0
        count = 0
        totalLength = 0

    if thisNode.strip() == 'A':
        count += 1
        totalLength += int(thisLen)
    oldKey = thisKey
    oldLen = thisLen

if oldKey != None:
    if count > 0:
        print oldKey,'\t',oldLen,'\t',float(totalLength/count)
    else:
        print oldKey,'\t',oldLen,'\t',0

