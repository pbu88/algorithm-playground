S = raw_input()
state1 = state2 = state3 = S[0]
p1 = p2 = p3 = 0
for pref in S[1:]:
    if pref != state1:
        p1 += 1
        state1 = pref
    if pref != 'U':
        p1 += 1
        state1 = 'U'

    if pref != state2:
        p2 += 1
        state2 = pref
    if pref != 'D':
        p2 += 1
        state2 = 'D'

    if pref != state3:
        p3 += 1
        state3 = pref

print "%s\n%s\n%s" % (p1, p2, p3)
