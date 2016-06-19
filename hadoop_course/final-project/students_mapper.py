#!/usr/bin/python

import sys
import csv

reader = csv.reader(sys.stdin, delimiter='\t')
count = 0
for line in reader:
    if count != 0:
        hour = line[8].strip().split(" ")[1][0]+line[8].strip().split(" ")[1][1]
        print line[3],"\t",hour
    count+=1
