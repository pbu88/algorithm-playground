import sys

case = 1
for line in sys.stdin:
    l = map(int, line.split(' '))[1:]
    ma, mi = max(l), min(l)
    print "Case %s: %s %s %s" % (case, mi, ma, ma-mi)
    case += 1
