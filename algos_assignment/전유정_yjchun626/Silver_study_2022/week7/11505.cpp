#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
 
#define endl '\n'
 
using namespace std;
 
typedef long long ll;
 
int n, m, k;
ll arr[1000001];
vector<ll> tree;
 
ll make_tree(int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];
 
    int mid = (start + end) / 2;
    return tree[node] = (make_tree(node * 2, start, mid) * make_tree(node * 2 + 1, mid + 1, end)) % 1000000007;
}
 
ll query(int node, int start, int end, int left, int right)
{
    if (left > end || start > right) return 1;
 
    if (left <= start && end <= right) return tree[node];
 
    int mid = (start + end) / 2;
    return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right))%1000000007;
}
 
void update(int node, int start, int end, int idx, ll value)
{
    if (idx < start || end < idx) return;
 
    if (start == end)
    {
        tree[node] = value;
        return;
    }
 
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    freopen("input.txt", "r", stdin);
 
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
 
    tree.resize(n * 4);
 
    make_tree(1, 1, n);
 
    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, 1, n, b, c);
        else
            cout << query(1, 1, n, b, c) << endl;
    }
 
    return 0;
}
