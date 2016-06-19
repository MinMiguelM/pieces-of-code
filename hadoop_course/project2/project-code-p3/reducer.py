#!/usr/bin/python

import sys

oldPage = None
count = 0
biggest = 0
famousPage = None

for line in sys.stdin:
    data_mapped = line.strip().split()
    if len(data_mapped) != 1:
        continue

    page = data_mapped

    if oldPage and oldPage != page:
        if count > biggest:
            biggest = count
            famousPage = oldPage
        count = 0

    oldPage = page
    count += 1

if oldPage != None:
    if count > biggest:
        biggest = count
        famousPage = oldPage
print famousPage, "\t", biggest
