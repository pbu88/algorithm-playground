first = True
while 1:
    n = int(raw_input())
    if not n: break
    if not first:
        print
    else:
        first = False
    l1 = map(int, [raw_input() for x in range(n)])
    l2 = map(int, [raw_input() for x in range(n)])
    d = {k:v for k,v in zip(sorted(l1), sorted(l2))}
    for i in l1:
        print d[i]
