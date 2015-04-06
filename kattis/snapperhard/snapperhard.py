t = int(raw_input())
for i in range(1, t+1):
    a, b = map(int, raw_input().split(' '))
    if b%2**a == -1%2**a:
        print 'Case #%s: ON' % i
    else:
        print 'Case #%s: OFF' % i
