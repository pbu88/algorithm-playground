n = int(raw_input())
ings = []
for _ in range(n):
    s, b = map(int, raw_input().split(' '))
    ings.append((s,b))

import itertools
mi = 0x7FFFFFFF
for i in range(len(ings)):
    combs = itertools.combinations(ings, i+1)
    for s in combs:
        total = reduce((lambda t1, t2: (t1[0]*t2[0], t1[1]+t2[1])), s)
        total = abs(total[0]-total[1])
        if total < mi:
            mi = total
print mi
