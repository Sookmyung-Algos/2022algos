import math
nINF = -math.inf

def bf(start):
    dist[start] = 0
 
    for i in range(n):
        for cur in range(1, n+1):
            for (next, cost) in graph[cur]:
                nextCost = dist[cur] + cost
 
                if dist[cur] != nINF and dist[next] < nextCost:
                    dist[next] = nextCost
                    route[next] = cur
                    
                    if i == n-1:
                        dist[next] = math.inf 
 
if __name__ == '__main__':
    n, m = map(int, input().split())
 
    graph = [[] for _ in range(n+1)]
    dist = [nINF] * (n+1)
    route = [0] * (n+1)
 
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
 
    bf(1)
    res = [n]
 
    if dist[n] != math.inf:
        node = n
 
        while node != 1:
            node = route[node]
            res.append(node)
 
        for i in reversed(res):
            print(i, end=' ')
        print()
    else:
        print('-1')
