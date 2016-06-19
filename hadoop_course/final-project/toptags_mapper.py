#!/usr/bin/python

import sys
import csv

reader = csv.reader(sys.stdin, delimiter='\t')
count = 0
for line in reader:
    if count != 0:
        tagnames = line[2].strip().split(' ')
        if line[5] == 'question':
            for i in tagnames:
                print i
    count+=1
