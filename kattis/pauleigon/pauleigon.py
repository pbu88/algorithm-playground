import math
N, P, Q = map(int, raw_input().split(' '))
d = (P+Q) / float(N)
d = int(math.floor(d)) + 1
if d % 2 == 0:
    print 'opponent'
else:
    print 'paul'
