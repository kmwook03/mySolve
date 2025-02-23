import sys
from itertools import accumulate

input = sys.stdin.readline

n, m = map(int, input().split())

matrix = [[0 for _ in range(n)] for _ in range(n)]

def matrixArea(x1, y1, x2, y2, matrix) :
    
    if y1-1 >= 0 :
        m1 = matrix[x2][y1-1]
    else :
        m1 = 0
    if x1-1 >= 0 :
        m2 = matrix[x1-1][y2]
    else :
        m2 = 0
    if m1 != 0 and m2 != 0 :
        p1 = matrix[min(x2, x1-1)][min(y1-1, y2)]
    else :
        p1 = 0

    result = matrix[x2][y2] - m1 - m2 + p1
    return result

for i in range(n) :
    n_lst = list(accumulate(map(int, input().split())))
    if i != 0 :
        for j in range(n) :
            matrix[i][j] = matrix[i-1][j] + n_lst[j]
    else :
        matrix[i] = n_lst

for i in range(m) :
    x1, y1, x2, y2 = map(int, input().split())
    x1 -= 1
    y1 -= 1
    x2 -= 1
    y2 -= 1
    print(matrixArea(x1, y1, x2, y2, matrix))