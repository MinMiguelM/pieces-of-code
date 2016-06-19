#!/usr/bin/python
"""
Your mapper function should print out 10 lines containing longest posts, sorted in
ascending order from shortest to longest.
Please do not use global variables and do not change the "main" function.
"""
import sys
import csv
import re


reader = csv.reader(sys.stdin, delimiter='\t')
count = 0
for line in reader:
    if count != 0:
        data = re.split('[\.\,\!\?\:\;\"\(\)\<\>\[\]\#\$\=\-/ ]',line[4])
        #data = line[4].strip().split(".,!?:;\"()<>[]#$=-/ ")
        for word in data:
            if word != '' and word != ' ' and word != '\n':
                print word.replace(" ","").lower(),"\t",line[0]
    count+=1
