from sys import stdin, stdout


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)

for _ in range(int(read())):
    s = read()
    t = read()

    ok = False
    for i in range(len(s)):
        for j in range(i, len(s)):
            

    print('YES' if ok else 'NO')
