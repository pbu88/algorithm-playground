import sys
import string

for l in sys.stdin:
    l = l.split(' ')
    name = ''
    numbers = []
    nums = []
    words = []
    for i in range(len(l)):
        if l[i][0] in string.digits:
            nums.append(float(l[i]))
        else:
            words.append(l[i])
    avg = sum(nums)/len(nums)
    print "%.6f %s" % (avg, ' '.join(words))
