import sys

def print_indexes(lst, max):
    print(max)
    count = 0
    count1 = 0
    for i in range(len(lst)):
        if (lst[i] == max):
            count += 1
    for i in range(len(lst)):
        if (lst[i] == max and count1 < count):
            print(i + 1, end = " ")
            count1 += 1
        elif (lst[i] == max and count1 == count):
            print(i + 1)

def read_first_number():
    str = ""
    c = sys.stdin.read(1)
    while (c != '\n'):
        str+=c
        c = sys.stdin.read(1)
    return (int(str))

def read_line(n):
    lst = []
    c = ''
    max = 0
    while (n > 0):
        str = ""
        while (c != " " and c != '\n'):
            str += c
            c = sys.stdin.read(1)
        if (int(str) > max):
            max = int(str)
        lst.append(int(str))
        n -= 1
        while (c == " "):
            c = sys.stdin.read(1)
    return (lst, max)

n = read_first_number()
lst, max = read_line(n)
print_indexes(lst, max)