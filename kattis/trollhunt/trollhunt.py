import math
b, k, g = map(int, raw_input().split(' '))
print int(math.ceil(float((b-1))/(k/g)))
