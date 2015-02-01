import string
s = raw_input()
l = float(len(s))

print s.count('_')/l
print len(filter(lambda x: x in string.ascii_lowercase, s))/l
print len(filter(lambda x: x in string.ascii_uppercase, s))/l
print len(filter(lambda x: x not in string.ascii_letters+'_', s))/l
