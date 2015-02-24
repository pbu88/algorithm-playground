n, l = map(int, raw_input().split(' '))
pos = 0
res = 0
for i in range(n):
    d, r, g = map(int, raw_input().split(' '))
    res += d-pos
    pos = d
    aux = res % (r+g)
    if aux < r:
        res+= r-aux

print res+(l-pos)

