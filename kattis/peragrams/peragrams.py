from collections import defaultdict
d = defaultdict(int)
s = raw_input()
for c in s:
    d[c]+=1
odds = len([x for x in d.values() if x%2])
if odds:
    print odds - 1
else:
    print 0

