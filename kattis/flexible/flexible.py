w, _ = map(int, raw_input().split(' '))
plist = [0] + map(int, raw_input().split(' ' )) + [w]
res = []
for i in xrange(1, len(plist)):
    for j in xrange(i-1,-1, -1):
        res.append(plist[i] - plist[j])

print ' '.join(map(str, sorted(set(res))))
