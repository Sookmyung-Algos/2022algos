N,X = map(int,input().split())
 
arr = list(map(int,input().split()))
 
if max(arr) == 0:
    print('SAD')
else:
    value = sum(arr[:X])
 
    max_value = value
    max_cnt = 1
 
    for i in range(X,N):
        value += arr[i]
        value -= arr[i-X]
        if value > max_value:
            max_value = value
            max_cnt = 1
        elif value == max_value:
            max_cnt += 1
 
    print(max_value)
    print(max_cnt)
