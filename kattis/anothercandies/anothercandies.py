import sys
t = int(raw_input())
for i in range(t):
    raw_input()
    n = int(raw_input())
    candies = 0
    for i in range(n):
        candies += int(raw_input())

    if candies%n == 0:
        print 'YES'
    else:
        print 'NO'


