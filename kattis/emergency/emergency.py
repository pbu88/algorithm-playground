n, k = map(int, raw_input().split(' '))
n-=1
if n<k*2:
    print n
else:
    print k + n%k + 1
