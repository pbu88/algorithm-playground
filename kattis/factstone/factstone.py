import math
import sys
def sol(line):
    y = int(line)
    if not y: return
    t = (y-1960) / 10
    b = 4 << t
    r = 0
    i = 2
    while True:
        aux = math.log(i, 2)
        if math.ceil(r+aux) > b: break
        i+=1
        r += aux
    print i-1



map(sol, sys.stdin)
