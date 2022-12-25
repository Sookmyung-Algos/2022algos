import sys
input = sys.stdin.readline

n,m = map(int,input().split())
graph = [[float('inf')]*(n) for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a-=1;b-=1
    graph[a][b] = 1
    graph[b][a] = 1

for k in range(n):
    graph[k][k] = 0
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

minn = float('inf')
ans = 0
for i in range(n):
    tmp = sum(graph[i])
    if minn > tmp:
        minn = tmp
        ans = i
print(ans+1)
