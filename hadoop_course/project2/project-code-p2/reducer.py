#!/usr/bin/python

import sys

oldPage = None
count = 0

for line in sys.stdin:
    data_mapped = line.strip().split()
    if len(data_mapped) != 1:
        continue

    page = data_mapped

    if oldPage and oldPage != page:
        print oldPage, "\t", count
        oldPage = page;
        count = 0

    oldPage = page
    count += 1

if oldPage != None:
    print oldPage, "\t", count

