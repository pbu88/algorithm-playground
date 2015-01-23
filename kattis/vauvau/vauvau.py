a, b, c, d = map(int, raw_input().split(' '))
p, m, g = map(int, raw_input().split(' '))
d1, d2 = a + b, c + d
pv = [(p % d1 or p) <= a, (p % d2 or p) <= c]
mv = [(m % d1 or m) <= a, (m % d2 or m) <= c]
gv = [(g % d1 or g) <= a, (g % d2 or g) <= c]

for l in [pv, mv, gv]:
    if all(l): print 'both'
    elif any(l): print 'one'
    else: print 'none'
