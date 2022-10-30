import sys
INF = sys.maxsize
input = sys.stdin.readline

def bellmanford(N, dp, graph):
    dp[1] = 0
    for r in range(N):
        for i in range(1, N+1):
            for nn, weight in graph[i]:
                if dp[nn] > dp[i] + weight:
                    dp[nn] = dp[i] + weight
                    if r == N-1:
                        return False
    return True

tc = int(input())
for test_case in range(tc):
    n, m, w = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    dp = [INF] * (n+1)
    for _ in range(m):
        s, e, t = map(int, input().split())
        graph[s].append([e,t])
        graph[e].append([s,t])
    for _ in range(w):
        s, e, t = map(int, input().split())
        graph[s].append([e,-t])
    if bellmanford(n, dp, graph):
        print("NO")
    else:
        print("YES")
