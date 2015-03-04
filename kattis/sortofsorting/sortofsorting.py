first = True
while 1:
    n = int(raw_input())
    if not n:
        break
    if not first:
        print
    first = False
    l = [raw_input() for _ in range(n)]
    l =sorted(l, key=lambda s: s[:2])
    print '\n'.join(l)

