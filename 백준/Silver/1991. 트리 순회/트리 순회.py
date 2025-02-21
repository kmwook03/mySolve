import sys

input = sys.stdin.readline

def PreOrder(node, graph) :
    if node == '.' :
        return
    print(node, end="")
    PreOrder(graph[node][0], graph)
    PreOrder(graph[node][1], graph)

def InOrder(node, graph) :
    if node == '.' :
        return
    left, right = graph[node]
    InOrder(left, graph)
    print(node, end="")
    InOrder(right, graph)
    

def PostOrder(node, graph) :
    if node == '.' :
        return
    left, right = graph[node]
    PostOrder(left, graph)
    PostOrder(right, graph)
    print(node, end="")

n = int(input())

graph = {}

for _ in range(n) :
    n1, n2, n3 = input().split()
    graph[n1] = [n2, n3]

PreOrder('A', graph)
print()
InOrder('A', graph)
print()
PostOrder('A', graph)
    