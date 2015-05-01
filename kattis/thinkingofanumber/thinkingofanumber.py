def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(max(a, b), min(a, b))

def lcmm(*args):
    return reduce(lcm, args)

while 1:
    clues = int(raw_input())
    if not clues: break
    divisors = []
    gt = 0
    lt = 1<<33
    for i in range(clues):
        clue = raw_input()
        if clue.startswith('divisible by'):
            divisors.append(int(clue.split(' ')[-1]))
        elif clue.startswith('greater than'):
            gt = max(gt, int(clue.split(' ')[-1]))
        elif clue.startswith('less than'):
            lt = min(lt, int(clue.split(' ')[-1]))
    if lt == 1<<33:
        print 'infinite'
        continue
    if divisors:
        _lcm = lcmm(*divisors)
    else:
        _lcm = 1
    l = [str(i) for i in range(_lcm, lt, _lcm) if i>gt]
    if not l:
        print 'none'
    else:
        print ' '.join(l)
