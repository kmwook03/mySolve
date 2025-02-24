import sys

input = sys.stdin.readline

a, b, c = map(int, input().split())

def MyPower(a, b, c) :
    result = 1
    a = a % c

    while b :
        if b % 2 == 1 :
            result = (result * a) % c
        a = (a * a) % c
        b = b // 2
    return result
        

print(MyPower(a, b, c))