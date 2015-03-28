t = int(raw_input())
for j in range(1,t+1):
    n = int(raw_input())
    v1 = map(int, raw_input().split(' '))
    v2 = map(int, raw_input().split(' '))
    v1 = sorted(v1)
    v2 = sorted(v2, reverse=True)
    print 'Case #%s: %s' % (j, sum(v1[i]*v2[i] for i in range(n)))
