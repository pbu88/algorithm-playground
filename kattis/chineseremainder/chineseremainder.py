def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1: return 1
    while a > 1:
        q = a / b
        a, b = b, a%b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0: x1 += b0
    return x1

def chinese_remainder(n, a, lena):
    p = i = prod = 1; sm = 0
    for i in range(lena): prod *= n[i]
    for i in range(lena):
        p = prod / n[i]
        sm += a[i] * mul_inv(p, n[i]) * p
    return sm % prod

n = int(raw_input())
for i in range(n):
    a,n,b,m = map(int, raw_input().split(' '))
    res = chinese_remainder([n,m],[a,b],2)
    print "%d %d" % (res%(n*m), n*m)
