# Idea: Dynamic programming
# Definitions:
# k = numbers of zeros between cases
# Tn-1 = Total of case n-1
# Mn-1 = cases in n-1 where it's leading '1' is gone
# Ln-1 = cases in n-1 where its leading '1' doesn't move

# Recursive formula:
# Just count
# Tn = (cases where its leading '1' doesn't move
#       + cases where its leading '1' moves
#         but case n-1's leading '1' doesnt move
#       + cases where its leading '1' moves and
#         case n-1's leading '1' also moves
#
# Case N:
# Tn = Tn-1 + k(Ln-1) + (k+1)Mn-1
#
# Base case:
#
# if string ends with one
#     T0 = 1
#     M0 = 0
# else
#    T0 = k+1
#    M0 = k

s = raw_input()[::-1].rstrip('0')
if len(s) == 0:
    print 1
else:
    if s[0] != '0':
        k = 0
        T = 1
        M = 0
    else:
        k=s.find('1')
        T = k+1
        M = k

    j = k+1
    k = 0
    for i in range(j, len(s)):
        if s[i] == '0':
            k += 1
        else:
            T_ = T
            T = T_ * (k+1) + M
            M = T - T_
            k = 0

    print T % 1000000009
