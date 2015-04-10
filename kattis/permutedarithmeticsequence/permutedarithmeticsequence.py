n = int(raw_input())
for i in range(n):
    l = map(int, raw_input().split(' '))[1:]
    l1 = sorted(l)
    dif = abs(l1[0]-l1[1])
    difo = abs(l[0]-l[1])
    res = True
    reso = True
    for i in range(2,len(l)):
        if dif != abs(l1[i-1]-l1[i]):
            res = False
        if difo != abs(l[i-1]-l[i]):
            reso = False
    if reso:
        print 'arithmetic'
    elif res and l==l1:
        print 'arithmetic'
    elif res:
        print 'permuted arithmetic'
    else:
        print 'non-arithmetic'

