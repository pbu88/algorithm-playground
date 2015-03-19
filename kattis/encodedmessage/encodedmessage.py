import math
n = int(raw_input())
for _ in range(n):
    msg = raw_input()
    l = len(msg)
    sq = int(math.sqrt(l))
    s = ''
    for i in range(sq-1,-1,-1):
        for j in range(sq):
            s+=msg[i+(j*sq)]
    print s
