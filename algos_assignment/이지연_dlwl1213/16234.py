import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
 
def dfs(arr, visited, x, y):
    visited[x][y]=1
    for i in range(4):
        nx, ny = x+dx[i], y+dy[i]
        if 0<=nx<n and 0<=ny<n and not visited[nx][ny]:
            if l<= abs(arr[x][y]-arr[nx][ny]) <=r:
                temp.append((nx, ny))
                dfs(arr, visited, nx, ny)
    return temp
 
n, l, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
 
answer=0
while True:
    visited = [[0]*n for _ in range(n)]
    flag = False
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    for a in range(n):
        for b in range(n):
            temp = [(a, b)]
            if not visited[a][b]:
                temp = dfs(arr, visited, a, b)
 
                if len(temp)>1:
                    flag = True
                    sum = 0
                    for x, y in temp:
                        sum += arr[x][y]
                    avg = sum//len(temp)
 
                    for i, j in temp:
                        arr[i][j] = int(avg)
                    
    if not flag:
        print(answer)
        exit(0)
    
    answer += 1
