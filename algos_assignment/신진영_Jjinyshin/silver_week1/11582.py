N = int(input())
c_lst = list(map(int, input().split()))
k = int(input())

idx = N // k
arr = []

for i in range(0,N,idx):
    arr = c_lst[i:i+idx]
    arr.sort()
    for j in arr:
        print(j, end=' ')
