n = int(raw_input())
for i in xrange(1, n+1):
    R, B = [], []
    l = int(raw_input())
    S = raw_input().split(' ')
    for s in S:
        if s[-1] == 'R':
            R.append(int(s[:-1]))
        else:
            B.append(int(s[:-1]))

    R = sorted(R, reverse=True)
    B = sorted(B, reverse=True)

    mi = (min(len(R), len(B)))
    r = sum(R[:mi]) + sum(B[:mi]) - mi*2

    print "Case #%s: %s" % (i, r)
