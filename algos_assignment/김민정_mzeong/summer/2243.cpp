#include <iostream>
using namespace std;
using ll = long long;
const int n_ = 1000000;

int tree[n_*4];
int n, a, b, c;

void update(int node, int s, int e, int idx, int val) {
    if (idx < s || e < idx) return;
    if (s == e) tree[node] += val;
    else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, val);
        update(node * 2 + 1, mid + 1, e, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int query(int node, int s, int e, int x) {
    if (s == e) {
        update(1, 1, n_, s, -1); // 한 개의 사탕이 꺼내짐
        return s;
    }
    int mid = (s + e) / 2;
    if (tree[node * 2] >= x) return query(node * 2, s, mid, x); // 왼쪽 자식 노드에 x개 이상의 사탕이 있을 때 왼쪽 자식 노드에서 x번째 사탕을 꺼낼 수 있음 
    else return query(node * 2 + 1, mid + 1, e, x - tree[node * 2]); // 왼쪽 자식 노드에 있는 사탕 모두 꺼내고 오른쪽 자식 노드에서 추가로 사탕을 꺼냄 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 1) { // 사탕상자에서 b순위의 사탕을 꺼냄
            cin >> b;
            cout << query(1, 1, n_, b) << "\n";
        }
        if (a == 2) { // 사탕상자에서 b맛의 사탕을 c개 넣음
            cin >> b >> c;
            update(1, 1, n_, b, c);
        }
    }
    return 0;
}
