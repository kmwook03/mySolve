import sys

input = sys.stdin.readline

n, k = map(int, input().split())
products = []

for _ in range(n) :
    p = list(map(int, input().split()))
    products.append(p)

dp = [[0 for _ in range(k+1)] for _ in range(n+1)]
for i in range(1, n+1) :
    for w in range(1, k+1) :
        if products[i-1][0] <= w :
            dp[i][w] = max(dp[i-1][w], dp[i-1][w-products[i-1][0]]+products[i-1][1])
        else :
            dp[i][w] = dp[i-1][w]

print(dp[n][k])