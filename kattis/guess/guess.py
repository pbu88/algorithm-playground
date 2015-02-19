l, m = 1, 1000
while 1:
    g = (l+m)/2
    print g
    a = raw_input()
    if a == 'correct':
        exit(0)
    elif a == 'higher':
        l=g+1
    else:
        m=g-1
