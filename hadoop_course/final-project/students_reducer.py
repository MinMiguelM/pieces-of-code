#!/usr/bin/python

import sys

oldKey = None
hoursGeneral = []
hours = []

def maximum():
    maxi = 0
    list_ret = []
    for i in hours:
        if maxi < hoursGeneral.count(i):
            maxi = hoursGeneral.count(i)
            list_ret = []
            list_ret.append(int(i))
        else:
            if maxi == hoursGeneral.count(i):
                list_ret.append(int(i))
    list_ret.sort()
    return list_ret

for line in sys.stdin:
    data_mapped = line.strip().split("\t")
    if len(data_mapped) != 2:
        # Something has gone wrong. Skip this line.
        continue

    thisKey, thisNode = data_mapped

    if oldKey and oldKey != thisKey:
        list_ret = maximum()
        for i in list_ret:
            print oldKey, "\t", i
        oldKey = thisKey;
        hours = []
        hoursGeneral = []

    if thisNode not in hours:
        hours.append(thisNode)

    oldKey = thisKey
    hoursGeneral.append(thisNode)

if oldKey != None:
    list_ret = maximum()
    for i in list_ret:
        print oldKey, "\t", i

