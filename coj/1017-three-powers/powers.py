while 1:
    s = raw_input()
    if s == '0':
        break
    if s == '1':
        print '{ }'
        continue
    output = '{ '
    n = long(s) - 1
    i = 0
    f = 1 << i
    first = True

    while(n >= f):
        if f & n != 0:
            if first:
                output += '%d'%(3**i)
                first = False
            else:
                output += ', %d'%(3**i)
        i += 1
        f = f << 1
    output += ' }'
    print output