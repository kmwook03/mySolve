import sys
from collections import deque

input = sys.stdin.readline

def bfs(start, target) :
    queue = deque([(start, 1)])
    visited = set([start])

    while queue :
        num, cnt = queue.popleft()

        if num == target :
            return cnt
        
        next_nums = [num * 2, num*10 + 1]

        for next_num in next_nums :
            if next_num <= target and next_num not in visited :
                queue.append((next_num, cnt + 1))
                visited.add(next_num)
    return -1

a, b = map(int, input().split())

print(bfs(a, b))