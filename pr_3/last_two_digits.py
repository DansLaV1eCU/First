import sys

def modular_exponentiation(base, exponent, mod):
    result = 1
    base = base % mod
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % mod
        exponent = exponent // 2
        base = (base * base) % mod
    return result

def read_number():
    str = ""
    while (True):
        c = sys.stdin.read(1)
        if (c == '\n' or c == ''):
            break
        str += c
    return (str)

A = read_number()
B_binary_str = read_number()
if len(A) >= 2:
    A = int(A[-2:])
else:
    A = int(A)
B = int(B_binary_str, 2)
last_two_digits = modular_exponentiation(A, B, 100)
print(last_two_digits)
