import sys
n = int(raw_input())
M, S = reduce(lambda t1, t2: [t1[0]+t2[0], t1[1]+t2[1]],
              [map(int, l.split(' ')) for l in sys.stdin])
res =  S/float(M*60)
if res <= 1.0:
    print 'measurement error'
else:
    print res
