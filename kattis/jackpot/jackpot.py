def gcd(a, b):
    if b==0:
        return a
    a, b = max(a,b), min(a,b)
    return gcd(b, a%b)

def lcm(a,b):
    return (a*b)/gcd(a,b)

def lcmm(*args):
    return reduce(lcm, args)

n = int(raw_input())
for i in range(n):
    w = int(raw_input())
    wl = map(int, raw_input().split(' '))
    r = lcmm(*wl)
    if r > 1000000000:
        print 'More than a billion.'
    else:
        print r
