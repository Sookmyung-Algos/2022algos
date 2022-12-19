import sys

edges = [[] for i in range(n+1)]
INF = sys.maxsize
result = []

n, m = map(int, sys.stdin.readline().rstrip().split())

for i in range(m):
    u, v, w = map(int, sys.stdin.readline().rstrip().split())
    edges[u].append([v, w])

def bf(start):
    dist = [-INF for i in range(n+1)]
    dist[start] = 0
    path = [0 for i in range(n+1)]

    for i in range(n):
        for cur_node in range(1, n+1):
            for next_node, next_cost in edges[cur_node]:
                if dist[cur_node] != -INF and dist[next_node] < next_cost + dist[cur_node]:
                    dist[next_node] = next_cost + dist[cur_node]
                    path[next_node] = cur_node

                    if i == n - 1: 
                        dist[next_node] = INF

    cur_node = n

    if dist[n] == INF:
        print(-1)
        return

    while cur_node != 1:
        result.append(cur_node)
        cur_node = path[cur_node]

    result.append(cur_node)
    result = result[::-1]
    print(*result, sep=' ')

    return

bf(1)

# 출처: https://velog.io/@j_aion/%EB%B0%B1%EC%A4%80-1738-%EA%B3%A8%EB%AA%A9%EA%B8%B8
