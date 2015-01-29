from heapq import heappush, heappop
from collections import defaultdict

pq = []                         # list of entries arranged in a heap
entry_finder = {}               # mapping of tasks to entries
REMOVED = '<removed-task>'      # placeholder for a removed task

def add_task(t):
    task, count, priority = t
    'Add a new task or update the priority of an existing task'
    entry = [priority, count, task]
    entry_finder[task] = entry
    heappush(pq, entry)

def remove_task(task):
    'Mark an existing task as REMOVED.  Raise KeyError if not found.'
    entry = entry_finder.pop(task)
    entry[-1] = REMOVED

def pop_task():
    'Remove and return the lowest priority task. Raise KeyError if empty.'
    while pq:
        priority, count, task = heappop(pq)
        if task is not REMOVED:
            del entry_finder[task]
            return task
    raise KeyError('pop from an empty priority queue')

d = defaultdict(lambda: 1)
n = int(raw_input())
inp = []
for i in xrange(n):
    x = int(raw_input())
    d[x] += 1
    inp.append(x)

map(add_task, ((i, i, d[i]) for i in xrange(1, n+2)))

res = []
for i in inp:
    prio = entry_finder[i][0]
    res.append(str(pop_task()))
    remove_task(i)
    add_task((i, i, prio-1))

if pq[0][2] != n+1 or pq[0][0] != 1:
    print "Error"
else:
    for i in xrange(0, len(res),100):
        print '\n'.join(res[i:i+100])

