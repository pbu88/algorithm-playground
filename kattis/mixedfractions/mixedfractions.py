while True:
    num, den = map(int, raw_input().split(' '))
    if num == den == 0:
        break
    print "{} {} / {}".format(num/den, num%den, den)
