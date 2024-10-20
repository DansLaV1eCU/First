import sys

def main_cycle(nb1, nb2):
    result = 1
    nb1 = nb1 % 100
    while (nb2 > 0):
        if (nb2 % 2 == 1):
            result = (result * nb1) % 100
        nb2 = nb2 // 2
        nb1 = (nb1 * nb1) % 100
    return (result)

def read_number():
    str = ""
    while (True):
        c = sys.stdin.read(1)
        if (c == '\n' or c == ''):
            break
        str += c
    return (str)

nb1 = read_number()
nb2 = read_number()
if len(nb1) >= 2:
    nnb1 = int(nb1[-2:])
else:
    nnb1 = int(nb1)
nnb2 = int(nb2, 2)
result = main_cycle(nnb1, nnb2)
print(result)
