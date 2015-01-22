import operator
grades = []
for i in range(1, 6):
    grades.append((i, sum(map(int, raw_input().split(' ')))))
print "%s %s" % max(grades, key=operator.itemgetter(1))
