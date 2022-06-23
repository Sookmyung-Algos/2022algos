n, x = map(int, input().split())  # 블로그 일수, x일 동안 가장 많이 들어온 방문자
arr = list(map(int, input().split()))

if max(arr) == 0:
    print("SAD")
else:
    # prefix 만들기
    prefix = [0]
    for i, a in enumerate(arr):
        prefix.append(prefix[i] + a)

    left = 0
    right = x
    result = 0
    count = 0

    while right <= n:
        if right - left == x:
            if result < prefix[right] - prefix[left]:
                result = prefix[right] - prefix[left]
                count = 1
            elif result == prefix[right] - prefix[left]:
                count += 1
            left += 1
            right += 1

    print(result)
    print(count)
