import random

with open('in', 'w') as infile:
    n = int(5e4)
    infile.write("{}\n".format(n))
    for _ in range(n):
        infile.write("{} {}\n".format(random.randint(int(29e4), int(3e5)), random.randint(0, int(3e5))))