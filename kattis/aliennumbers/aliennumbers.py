n = int(raw_input())
for k in range(n):
    d1 = {}
    d2 = {}
    num, base, basetarget = raw_input().split(' ')
    for i, c in enumerate(base):
        d1[c] = i

    for i, c in enumerate(basetarget):
        d2[c] = i

    s = ''
    n = 0
    for i, c in enumerate(num[::-1]):
        n+=d1[c]*(len(base)**i)

    s1 = ''
    while n > 0:
        rem, n = n % len(basetarget), n / len(basetarget)
        s1+=basetarget[rem]
    if s1 == '':
        s1 = basetarget[0]

    print "Case #%s: %s" % (k+1, s1[::-1])



