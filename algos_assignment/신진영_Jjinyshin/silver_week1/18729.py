N=int(input())
matrix = []
for i in range(N):
    temp=list(map(int, input().split()))
    matrix.append(temp)

def pooling(x,y,size):
  mid = size // 2
  if size == 2:
      n_list=[matrix[x][y], matrix[x+1][y], matrix[x][y+1], matrix[x+1][y+1]]
      n_list.sort()
      return n_list[-2]
  left_t = pooling(mid, x, y)
  right_t = pooling(mid, x+mid, y)
  left_b = pooling(mid, x, y+mid)
  right_b = pooling(mid, x+mid, y+mid)
  n_list = [left_t, right_t, left_b, right_b]
  n_list.sort()
  return n_list[-2]
print(pooling(N, 0, 0))
