raw_input()
l = sorted(map(int, raw_input().split(' ')))
r = [str(l[0])]
conseq = 1
i = 1
while i < len(l)-1:
    if (l[i-1] + 1) == l[i]:
        conseq += 1
        i+=1
        continue
    elif conseq > 1:
        s = ''
        if conseq > 2:
            s = '-'
        s += str(l[i-1])
        conseq = 1
        r.append(s)
    r.append(str(l[i]))
    i += 1
s = ''
if conseq > 2:
    s += '-'
s += str(l[-1])
print ' '.join(r)
