s = raw_input()
n = len(s)
i = 2
row = 1
while i*i <= n:
    if not n%i:
        row = i
    i+=1

col = n/row
res = ''
for i in range(row):
    for j in range(i, n, row):
        res += s[j]

print res
