import sys
from collections import deque

input = sys.stdin.readline

def dfs(graph, start, parents) :
    queue = deque([start])
    visited = set()
    visited.add(start)

    while queue :
        curr = queue.popleft()
        for node in graph[curr] :
            if node not in visited :
                parents[node] = curr
                visited.add(node)
                queue.append(node)

n = int(input())

graph = [[] for _ in range(n+1)]
parents = [0] * (n+1)

for _ in range(n-1) :
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

dfs(graph, 1, parents)

for i in range(2, n+1) :
    print(parents[i])