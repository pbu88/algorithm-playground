import math
h, v = map(int, raw_input().split(' '))
print int(math.ceil(h/math.sin(math.radians(v))))
