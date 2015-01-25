# Max Subarray problem
# Kadane's algorithm: http://en.wikipedia.org/wiki/Maximum_subarray_problem
def max_subarray(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

n, p = map(int, raw_input().split(' '))
students = map(lambda x: int(x) - p, raw_input().split(' '))

print max_subarray(students)
