import sys
for l in sys.stdin:
    N = int(l)
    if not N:
        break
    s = sum(int(i) for i in str(N))
    r = -1
    for i in range(11, 100):
        s_ = sum(int(x) for x in str(N*i))
        if s_ == s:
            r = i
            break
    if r > 0:
        print r
    else:
        print 100
