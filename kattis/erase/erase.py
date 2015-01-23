n, s1, s2 = (int(raw_input()), raw_input(), raw_input())
if n%2 == 0:
    if s1 == s2:
        print 'Deletion succeeded'
    else:
        print 'Deletion failed'
else:
    success = True
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            success = False
            break
    if success:
        print 'Deletion succeeded'
    else:
        print 'Deletion failed'
