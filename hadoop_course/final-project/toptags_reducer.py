#!/usr/bin/python

import sys

oldKey = None
oldLen = None
count = 0

def insert(tag,times,top):
    top = dict(top)
    if len(top) < 10:
        top[tag] = times
    else:
        if min(top.values()) < times:
            for i in top.keys():
                if top[i] == min(top.values()):
                    top[tag] = times
                    top.pop(i)
                    break
    return top

top10 = {}
for line in sys.stdin:
    thisKey = line.strip()

    if oldKey and oldKey != thisKey:
        top10 = insert(oldKey,count,top10)
        count = 0

    oldKey = thisKey
    count += 1

if oldKey != None:
    top10 = insert(oldKey,count,top10)
x = sorted (top10,key=top10.get,reverse=True)
for i in x:
    print i,'\t',top10[i]
