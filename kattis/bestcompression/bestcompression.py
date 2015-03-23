n, b = map(int, raw_input().split(' '))
print 'yes' if n <= 2**(b+1) - 1 else 'no'
