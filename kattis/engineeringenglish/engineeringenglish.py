import sys
d = {}
for line in sys.stdin:
    out = []
    line = line.rstrip('\n')
    for word in line.split(' '):
        _word = word.lower()
        if _word in d:
            out.append('.')
        else:
            d[_word] = 1
            out.append(word)
    print ' '.join(out)
