#!/usr/bin/python

import sys
import re

for line in sys.stdin:
    data = line.split()
    if len(data) == 10:
        path = data[6]
        if path[0] != "/":
            regex = re.sub("http://.*\.co\.uk","",path)
            if regex == "":
                print "/"
            else:
                print regex
        else:
            print path
