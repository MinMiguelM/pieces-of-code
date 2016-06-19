#!/usr/bin/python
"""
Your mapper function should print out 10 lines containing longest posts, sorted in
ascending order from shortest to longest.
Please do not use global variables and do not change the "main" function.
"""
import sys
import csv

count = 0
reader = csv.reader(sys.stdin, delimiter='\t')
writer = csv.writer(sys.stdout, delimiter='\t', quotechar='"', quoting=csv.QUOTE_ALL)

for line in reader:
    if count != 0:
        lineOutput = []
        if len(line) == 5:
            lineOutput.append(line[0])
            lineOutput.append("A")
            lineOutput.append(line[1])
            lineOutput.append(line[2])
            lineOutput.append(line[3])
            lineOutput.append(line[4])
        else:
            if len(line) == 19:
                lineOutput.append(line[3])
                lineOutput.append("B")
                lineOutput.append(line[0])
                lineOutput.append(line[1])
                lineOutput.append(line[2])
                lineOutput.append(line[5])
                lineOutput.append(line[6])
                lineOutput.append(line[7])
                lineOutput.append(line[8])
                lineOutput.append(line[9])
        writer.writerow(lineOutput)
    count += 1
