d = {}
while 1:
    s = raw_input()
    if s == '':
        break
    eng, foreign = s.split(' ')
    d[foreign] = eng

while 1:
    try:
        s = raw_input().rstrip('\n')
    except:
        break
    print d.get(s, 'eh')
