n = int(input())
dist = [[1e9 for i in range(26)] for i in range(26)]
for i in range(n):
    inList = input().split()
    start = ord(inList[0]) - ord('a')
    end = ord(inList[2]) - ord('a')
    dist[start][end] = 1

for k in range(26):
    for i in range(26):
        for j in range(26):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
m = int(input())
for i in range(m):
    inList = input().split()
    start = ord(inList[0]) - ord('a')
    end = ord(inList[2]) - ord('a')
    if dist[start][end] < 1e9:
        print('T')
    else:
        print('F')
