r, n = map(int, raw_input().split(' '))
rooms = [0]*(r+1)
for i in range(n):
    room = int(raw_input())
    rooms[room] = 1

room = -1
for i in range(1, r+1):
    if not rooms[i]:
        room = i
        break
if room<0:
    print 'too late'
else:
    print room

