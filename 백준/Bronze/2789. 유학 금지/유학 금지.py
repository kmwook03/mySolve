import sys

input = sys.stdin.readline

forbided = "CAMBRIDGE"
check = {}
for i in forbided :
    check[i] = 1

Email = input()
censored = ""

for i in Email :
    if check.get(i) == None :
        censored += i

print(censored)