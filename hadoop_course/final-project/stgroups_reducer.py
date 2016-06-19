#!/usr/bin/python

import sys

oldKey = None
students = []

for line in sys.stdin:
    data_mapped = line.strip().split('\t')

    thisKey, student = data_mapped

    if oldKey and oldKey != thisKey:
        print oldKey,'\t',students
        students = []

    oldKey = thisKey
    students.append(student)

if oldKey != None:
    print oldKey,'\t', students
