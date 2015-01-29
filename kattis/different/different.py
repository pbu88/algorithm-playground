import sys
for l in sys.stdin.readlines():
    a, b = map(int, l.split(' '))
    print abs(a-b)
