#!/usr/bin/python

import sys

for line in sys.stdin:
    data = line.split()
    if len(data) == 10:
        print data[6]
