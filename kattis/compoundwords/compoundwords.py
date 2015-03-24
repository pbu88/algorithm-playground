import sys
import itertools

words = set()
for l in sys.stdin:
    ws = set(l.rstrip('\n').split(' '))
    words = words.union(ws)

for w in sorted({w1+w2 for w1,w2 in itertools.permutations(words, 2)}):
    print w

