t = int(raw_input())
for j in range(1, t+1):
    n = int(raw_input())
    g = map(int, raw_input().split(' '))
    g = sorted(g)
    r = None
    for i in range(1, n-1):
        if g[i] != g[i-1] and g[i] != g[i+1]:
            r = g[i]
            break
    if r is None and g[0]!=g[1]:
        r = g[0]
    elif r is None and g[-1]!=g[-2]:
        r = g[-1]

    print 'Case #%s: %s' % (j, r)
