# Idea: Dynamic programming
# Theorem:
# 2^n = 2^n-1 + 2^n-2 + ... + 2 * 2^k for all k
#
# With this idea, we now that if bit N is set, then there are k+1 ways
# to represent it where k is the amount of zeros between bit N and
# next bit M (N > M)
#
# Ex:
# 100000 can also be written like this:
#  20000
#  12000
#  11200
#  11120
#  11112
#
# Definitions:
# k = numbers of zeros between cases
# Tn-1 = Total of case n-1
# Mn-1 = cases in n-1 where it's leading '1' is gone
# Ln-1 = cases in n-1 where its leading '1' doesn't move
#
# Tn = Mn + Ln
# Ln = Tn - Mn

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
#    = Tn-1 + k(Tn-1 - Mn-1) + (k+1)Mn-1
#    ... (after factorizing)
#    = (k+1)Tn-1 + Mn-1
#
# Mn = Tn - Tn-1
#
# Base case:
#
# if string ends with one
#     T0 = 1
#     M0 = 0
# else
#    T0 = k+1
#    M0 = k

# The implementation is up to you ;)
