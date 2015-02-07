n = int(raw_input())
from collections import Counter
dom = Counter()
for i in range(n):
    dom[raw_input()] += 1

res = 0
for i in range(n):
    s = raw_input()
    if dom[s] > 0:
        dom[s] -= 1
        res += 1

print res

