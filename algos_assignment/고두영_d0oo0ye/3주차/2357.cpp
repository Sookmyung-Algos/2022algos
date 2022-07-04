#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
const int MAX = 100000;

int a[MAX + 1];
pair<int, int> tree[MAX * 4];

pair<int, int> init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].first = a[start];
		tree[node].second = a[start];
		return tree[node];
	}

	int mid = (start + end) >> 1;
	
	pair<int, int> left = init(start, mid, node * 2);
	pair<int, int> right = init(mid + 1, end, node * 2 + 1);

	tree[node].first = min(left.first, right.first);
	tree[node].second = max(left.second, right.second);

	return tree[node];
}

pair<int, int> query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) 
    return { INT_MAX, 0 };
	if (left <= start && end <= right) 
    return tree[node];

	int mid = (start + end) >> 1;
  
	pair<int, int> l = query(start, mid, node * 2, left, right);
	pair<int, int> r = query(mid + 1, end, node * 2 + 1, left, right);

	pair<int, int> res;
	res.first = min(l.first, r.first);
	res.second = max(l.second, r.second);

	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
  
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	init(1, n, 1);

	while (m--)
	{
		int left, right;
		cin >> left >> right;
		pair<int, int> tmp = query(1, n, 1, left, right);
		cout << tmp.first << ' ' << tmp.second << '\n';
	}

}
