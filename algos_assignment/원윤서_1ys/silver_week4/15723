import sys

input = sys.stdin.readline
INF = int(1e9)
N = int(input())

alphabet = "abcdefghijklmnopqrstuvwxyz"
n = len(alphabet)
graph = [[INF] * n for i in range(n)]

for i in range(N):
    a, b = map(alphabet.index, input().rstrip().split(" is "))
    graph[a][b] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

M = int(input())
for i in range(M):
    a, b = map(alphabet.index, input().rstrip().split(" is "))
    if graph[a][b] == INF:
        print("F")
    else:
        print("T")

# 출처: https://velog.io/@hanbin/%EB%B0%B1%EC%A4%80-15723%EB%B2%88-n%EB%8B%A8-%EB%85%BC%EB%B2%95-with-Python
