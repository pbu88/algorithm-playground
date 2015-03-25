import itertools
n = raw_input()
perms = sorted(set(int(''.join(t)) for t in itertools.permutations(n)))
i = perms.index(int(n))
if i<len(perms)-1:
    print perms[i+1]
else:
    print 0
