#include <iostream>
using namespace std;

int arr[100001];
int solve[262145];

int init(int L, int R, int sI) {
    if (L == R) 
      return solve[sI] = arr[L];
    return solve[sI] = min(init(L, (L + R) / 2, sI * 2), init((L + R) / 2 + 1, R, sI * 2 + 1));
}

int query(int L, int R, int qL, int qR, int sI) {
    if (R < qL || qR < L) 
      return 1000000007;
    if (qL <= L && R <= qR) 
      return solve[sI];
    return min(query(L, (L + R) / 2, qL, qR, sI * 2), query((L + R) / 2 + 1, R, qL, qR, sI * 2 + 1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    init(1, N, 1);

    for (int T = 0; T < M; T++) {
        int x, y; cin >> x >> y;
        cout << query(1, N, x, y, 1) << '\n';
    }
}
