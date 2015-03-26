B = ['0','1','2','5','9','8','6']

import sys
for l in sys.stdin:
    n = int(l)
    res = ''
    while n:
        n, r = n/7, n%7
        res+=B[r]
    print res

