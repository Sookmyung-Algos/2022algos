n, m = map(int, input().split())
memory = [0] + list(map(int, input().split()))
cost = [0] + list(map(int, input().split()))
length = sum(cost)+1
dp = [[0 for _ in range(length)] for _ in range(n+1)]
ans = 10001

for i in range(1, n+1):
    ci, mi = cost[i], memory[i]
    for j in range(length):
        dp[i][j] = dp[i-1][j]
    for j in range(ci, length):
        dp[i][j] = max(dp[i-1][j-ci] + mi, dp[i][j])
        if dp[i][j] >= m:
            ans = min(ans, j)

print(ans)