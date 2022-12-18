import sys

input = sys.stdin.readline
INF = int(1e9)

def bf(start):
    dis = [INF] * (n+1)
    dis[start]=0
    for i in range(n):
        for edge in edges:
            cur = edge[0]
            next_node = edge[1]
            cost = edge[2]
            
            if dis[next_node] > cost + dis[cur]:
                dis[next_node] = cost + dis[cur]
                if i == n - 1:
                    return True
    return False

t = int(input())

for _ in range(t):
    # 지점 수, 도로 수, 웜홀 수
    n, m, w = map(int, input().split())
    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))
        
    key = bf(1)
    if key:
        print("YES")
    else:
        print("NO")
