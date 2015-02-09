import sys
S = []
m = -1
for line in sys.stdin:
    s = line.rstrip('\n')
    S.append(s)
    if len(s) > m:
        m = len(s)

sum = 0
for s in S[:-1]:
    sum += (m - len(s))**2

print sum
