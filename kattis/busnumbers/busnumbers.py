raw_input()
l = sorted(map(int, raw_input().split(' ')))
l.append(-1)
res = []
conseq = 1
prev = l[0]
for i in range(1, len(l)):
    curr = l[i]
    if curr == prev + 1:
        conseq += 1
    else:
        if conseq >= 3:
            res.append("%s-%s" % (l[i-conseq], str(l[i-1])))
        elif conseq == 2:
            res.append(str(l[i-1]-1))
            res.append(str(l[i-1]))
        else:
            res.append(str(l[i-1]))
        conseq = 1
    prev = curr

print ' '.join(res)

