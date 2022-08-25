#include <iostream>
#include <cmath>
#define INF 1000000007
#define MAX 1000001
using namespace std;

long long num[MAX];
long long* tree;

long long init(int node, int s, int e) {
    if (s == e) return tree[node] = num[s];
    int m = s + (e - s) / 2;
    return tree[node] = (init(2 * node, s, m) * init(2 * node + 1, m + 1, e)) % INF;
}

long long mul(int node, int s, int e, int l, int r) {
    if (l > e || r < s) 
        return 1;
    if (l <= s && e <= r) 
        return tree[node];
    int m = s + (e - s) / 2;
    return (mul(node * 2, s, m, l, r) * mul(node * 2 + 1, m + 1, e, l, r)) % INF;
}

long long update(int node, int s, int e, int idx, long long val) {
    if (idx > e || idx < s) return tree[node];
    if (s == e) return tree[node] = val;
    int m = s + (e - s) / 2;
    return tree[node] = (update(2 * node, s, m, idx, val) * update(2 * node + 1, m+ 1, e, idx, val)) % INF;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int N, M, K, h, a;
    long long b, c;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> num[i];

    h = ceil(log2(N));
    tree = new long long[1 << (h + 1)];
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            num[b - 1] = c;
            update(1, 0, N - 1, b - 1, c);
        } else {
            cout << mul(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}
