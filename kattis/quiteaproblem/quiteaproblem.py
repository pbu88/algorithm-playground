import sys

for line in sys.stdin:
    if 'problem' in line.lower():
        print 'yes'
    else:
        print 'no'
