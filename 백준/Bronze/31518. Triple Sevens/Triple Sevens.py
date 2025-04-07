import sys

input = sys.stdin.readline

n = int(input())

wheels = []
isSeven = []
for _ in range(3) :
    wheel = list(map(int, input().split()))
    if 7 in wheel :
        isSeven.append(True)
    else :
        isSeven.append(False)

if False in isSeven :
    print(0)
else :
    print(777)