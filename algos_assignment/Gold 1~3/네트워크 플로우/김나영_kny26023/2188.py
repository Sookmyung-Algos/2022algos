import sys
input = sys.stdin.readline

n, m = map(int, input().split())

start = [[] for i in range(n + 1)]
dest = [0 for i in range(m + 1)]

def dfs(s):
    if visit[s] == 1:
        return 0
    visit[s] = 1
    for i in start[s]:
        if dest[i] == 0 or dfs(dest[i]):
            dest[i] = s
            return 1
    return 0

for i in range(1, n + 1):
    a = list(map(int, input().split()))
    for j in a[1:]:
        start[i].append(j)

for i in range(1, n + 1):
    visit = [0 for _ in range(n + 1)]
    dfs(i)

print(len(dest) - dest.count(0))