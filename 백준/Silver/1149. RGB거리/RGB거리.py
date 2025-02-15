import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

cases = [[0,0,0] for _ in range(n)]
cases[0] = list(map(int, input().split()))

for i in range(1, n) :
    costs = list(map(int, input().split()))
    cases[i][0] = min(cases[i-1][1], cases[i-1][2]) + costs[0]
    cases[i][1] = min(cases[i-1][0], cases[i-1][2]) + costs[1]
    cases[i][2] = min(cases[i-1][1], cases[i-1][0]) + costs[2]

print(min(cases[-1]))