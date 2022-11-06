from collections import deque
import sys
input = sys.stdin.readline
INF = -sys.maxsize

def bellmanford(s, e):
    dp = [INF for _ in range(n)]
    dp[s] = money[s]
    for i in range(n-1):
        for u, v, w in city:
            if dp[u] != INF and dp[u]+w > dp[v]:
                dp[v] = dp[u]+w
    if dp[e] == INF:
        return "gg"
    for u, v, w in city:
        if dp[u] != INF and dp[u]+w > dp[v]:
            if bfs(v, e):
                return "Gee"
            else:
                pass
    return dp[e]

def bfs(start, end):
    q = deque()
    q.append(start)
    visit = [False] * (n)
    visit[start] = True
    while q:
        now = q.popleft()
        if now == end:
            return True
        for a, b, c in city:
            if a == now:
                if not visit[b]:
                    visit[b] = True
                    q.append(b)
    return False

n, s, e, m = map(int, input().split())
city = []

for _ in range(m):
    a, b, c = map(int, input().split())
    city.append([a, b, -c])

money= list(map(int, input().split()))

for i in range(m):
    city[i][2] = city[i][2] + money[city[i][1]]

print(bellmanford(s, e))