n = int(input())
count_op = []
track_count_num = 0

def make_one(n):
    if n == 1:
        return 0
    elif n <= 3: return 1
    return min(make_one(n//3) + n%3 + 1, make_one(n//2) + n%2 + 1)

print(make_one(n))
