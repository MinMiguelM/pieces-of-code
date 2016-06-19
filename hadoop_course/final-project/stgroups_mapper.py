#!/usr/bin/python

import sys
import csv

reader = csv.reader(sys.stdin, delimiter='\t')
count = 0
for line in reader:
    if count != 0:
        if line[5]== 'question':
            print line[0],'\t',line[3]
        else:
            print line[6],'\t',line[3]
    count+=1
