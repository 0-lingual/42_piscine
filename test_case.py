import random

n = int(input())
arr = [[i for i in range(1, n+1)] for _ in range(n)]

for i in range(n - 2):
    while True:
        random.shuffle(arr[i])
        good = True
        for j in range(n):
            for k in range(i):
                if arr[i][j] == arr[k][j]:
                    good = False
                    break
            if not good:
                break
        if good:
            break

last_two = []
for i in range(n):
    tmp = [j for j in range(1, n+1)]
    for j in range(n-2):
        tmp.remove(arr[j][i])
    last_two.append(tmp)

while True:
    for x in last_two:
        random.shuffle(x)
    tmp = set()
    for i in range(n):
        tmp.add(last_two[i][0])
    if len(set(tmp)) == n:
        for i in range(n):
            arr[-2][i], arr[-1][i] = last_two[i][0], last_two[i][1]
        break
print("[map %dx%d]" %(n, n))
print(*arr, sep='\n')

ans = [[0]*n for _ in range(4)]
for i in range(n):
    now = 0
    for j in range(n):
        if arr[j][i] > now:
            now = arr[j][i]
            ans[0][i] += 1
for i in range(n):
    now = 0
    for j in range(n-1, -1, -1):
        if arr[j][i] > now:
            now = arr[j][i]
            ans[1][i] += 1
for i in range(n):
    now = 0
    for j in range(n):
        if arr[i][j] > now:
            now = arr[i][j]
            ans[2][i] += 1
for i in range(n):
    now = 0
    for j in range(n-1, -1, -1):
        if arr[i][j] > now:
            now = arr[i][j]
            ans[3][i] += 1
print()
print("[input value]")
print('"',end='')
for i in range(len(ans)):
    if i == len(ans) - 1:
        print(*ans[i], end='')
    else:
        print(*ans[i], end=' ')
print('"')