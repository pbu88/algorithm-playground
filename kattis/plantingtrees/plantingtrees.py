n = int(raw_input())
T = sorted(map(int, raw_input().split()), reverse=True)
print max([i+v for i,v in enumerate(T, 1)]) + 1
