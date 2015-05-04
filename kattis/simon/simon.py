n = int(raw_input())

for _ in range(n):
    s = raw_input()
    if s.startswith('simon says'):
        print ' '.join(s.split()[2:])
    else:
        print

