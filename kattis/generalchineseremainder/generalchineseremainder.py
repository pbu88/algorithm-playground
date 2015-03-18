def lcm(a, b):
    return a * b / egcd(a, b)[0]

def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b/a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y

def chinese_reminder(mods, rems):
    n,m=mods
    a,b=rems
    _gcd,u,v = egcd(n,m)
    if abs(a-b) % _gcd:
        return None
    x1 = u*((b-a)/_gcd)
    return n*x1+a

n = int(raw_input())
for i in range(n):
    a,n,b,m = map(int, raw_input().split(' '))
    res = chinese_reminder([n,m],[a,b])
    if res is None:
        print "no solution"
    else:
        _lcm = lcm(n,m)
        print "%d %d" % ((res%_lcm), _lcm)
