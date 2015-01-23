s = raw_input()
vowels = ['a','e','i','o','u']
r = ''
i = 0
while i < len(s):
    r+=s[i]
    if s[i] in vowels:
        i+=2
    i+=1
print r
