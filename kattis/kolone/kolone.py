n,m = map(int, raw_input().split(' '))
s1 = raw_input()[::-1]
s2 = raw_input()
t = int(raw_input())
ls = [(i+t,2,l) for i,l in enumerate(s1)]
ls += [(n+i,1,l) for i,l in enumerate(s2)]
ls=sorted(ls)
from operator import add, itemgetter
print reduce(add, map(itemgetter(2),ls), '')
