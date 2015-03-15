def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b / a) * y, y)


while 1:
    n, t = map(int, raw_input().split(' '))
    if not (n+t): break
    for i in range(t):
        s = raw_input().split(' ')
        a, op, b = int(s[0]), s[1], int(s[2])
        if op == '+':
            print (a+b)%n
        if op == '-':
            print (a-b)%n
        if op == '*':
            print (a*b)%n
        if op == '/':
            if b == 0:
                print -1
                continue
            g, x, y = egcd(b, n)
            if g!=1:
                print -1
            else:
                print (x*(a/g))%n
