#!/usr/bin/python
"""
Your mapper function should print out 10 lines containing longest posts, sorted in
ascending order from shortest to longest.
Please do not use global variables and do not change the "main" function.
"""
import sys
import csv
from datetime import datetime

for line in sys.stdin:
    data = line.strip().split('\t')
    if len(data) == 6:
        weekday = datetime.strptime(data[0],"%Y-%m-%d").weekday()
        print weekday,'\t',data[4]
