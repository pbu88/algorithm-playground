D = [(1, 0), (0, 1), (1, 1)]
n = int(raw_input())
if n > 2:
    i = 3
    while i<=n:
        D.append((D[i-1][1], D[i-1][0] + D[i-1][1]))
        i += 1
print "%s %s" % D[n]
