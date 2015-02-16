C, n = map(int, raw_input().split())
curr_total = 0
possible = True
for l in range(n):
    a, b, c = map(int, raw_input().split(' '))
    if a > curr_total:
        possible = False
        break
    curr_total = curr_total - a + b
    if curr_total > C:
        possible = False
        break
    if c > 0 and curr_total < C:
        possible = False
        break

if curr_total > 0:
    possible = False

if possible:
    print "possible"
else:
    print "impossible"
