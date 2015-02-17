import sys
E, M = 365, 687
for i, l in enumerate(sys.stdin, 1):
    e, m = map(int, l.split(' '))
    if e == m == 0:
        print "Case %s: %s" % (i, 0)
        continue
    s = E - e
    m += s
    while m%M != 0:
        s+=E
        m+=E
    print "Case %s: %s" % (i, s)
