table = [1.0, 1000.0, 12.0, 3.0, 22.0, 10.0, 8.0, 3.0]
mapping = {
    'th':0,
    'thou':0,
    'in':1,
    'inch':1,
    'ft':2,
    'foot':2,
    'yd':3,
    'yard':3,
    'ch':4,
    'chain':4,
    'fur':5,
    'furlong':5,
    'mi':6,
    'mile':6,
    'lea':7,
    'league':7,
}

inp = raw_input().split(' ')
amount, frm, to = float(inp[0]), inp[1], inp[3]
steps = mapping[to] - mapping[frm]
step = 1 if steps > 0 else -1
steps=abs(steps)
for i in range(steps):
    if step > 0:
        amount/=table[mapping[frm]+i+1]
    else:
        amount*=table[mapping[frm]-i]

print amount
