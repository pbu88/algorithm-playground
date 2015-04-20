dp = {}

def other_player(p):
    return 'O' if p == 'S' else 'S'

def game(a, b, p):
    if dp.has_key((a,b)):
        if dp[(a,b)]:
            return p
        else:
            return other_player(p)
    if b == 0:
        dp[(a,b)] = False
        return other_player(p)
    a, b = max(a,b), min(a,b)
    w1 = game(b, a%b, other_player(p))
    w2 = w1
    if a > 2*b:
        w2 = game(a%b+b ,b, other_player(p))
    if p == w1 or p == w2:
        dp[(a,b)] = True
        return p
    dp[(a,b)] = False
    return w1

while 1:
    a, b = map(int, raw_input().split(' '))
    if a+b == 0:
        break
    if 'S' == game(a, b, 'S'):
        print 'Stan wins'
    else:
        print 'Ollie wins'

