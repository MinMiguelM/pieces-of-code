#!/usr/bin/python

import sys
import csv

reader = csv.reader(sys.stdin, delimiter='\t')
count = 0
for line in reader:
    if count != 0:
        if line[5] == 'question':
            print line[0],'\t','Q','\t',len(line[4])
        else:
            if line[5] == 'answer':
                print line[6],'\t','A','\t',len(line[4])
    count+=1
