import sys
input = sys.stdin.readline
INF = sys.maxsize

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
dp = [INF] * (n+1)
dp[1] = 0
tf = True

def bellmanford():
    global tf
    for r in range(n):
        for i in range(1, n+1):
            for nn, weight in graph[i]:
                if dp[i] != INF and dp[nn] > dp[i] + weight:
                    dp[nn] = dp[i] + weight
                    if r == n-1:
                        tf = False

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])

bellmanford()

if not tf:
    print(-1)
else:
    for i in dp[2:]:
        print(i if i != INF else -1)