#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>

using namespace std;

typedef long long ll;
#define MAX 400005

int n, m, a, b;
ll minTree[MAX*10];
ll maxTree[MAX*10];
ll node[MAX];

// init(배열, 위치, 시작점, 끝점)
ll minInit(ll arr[], ll treeIdx, ll dataIdxL, ll dataIdxR) {
	if (dataIdxL == dataIdxR) return minTree[treeIdx] = arr[dataIdxL - 1];
	ll mid = (dataIdxL + dataIdxR) / 2;
	return minTree[treeIdx] = min(minInit(arr, 2 * treeIdx, dataIdxL, mid), minInit(arr, 2 * treeIdx + 1, mid + 1, dataIdxR));
}

ll maxInit(ll arr[], ll treeIdx, ll dataIdxL, ll dataIdxR) {
	if (dataIdxL == dataIdxR) return maxTree[treeIdx] = arr[dataIdxL - 1];
	ll mid = (dataIdxL + dataIdxR) / 2;
	return maxTree[treeIdx] = max(maxInit(arr, 2*treeIdx, dataIdxL, mid), maxInit(arr, 2*treeIdx+1, mid+1, dataIdxR));
}

// query(시작위치, 끝위치, 위치, 시작점, 끝점)
ll minQuery(ll queryL, ll queryR, ll treeIdx, ll dataIdxL, ll dataIdxR) {
	if (queryL > dataIdxR || dataIdxL > queryR) return 1000000001;
	if (dataIdxL >= queryL && queryR >= dataIdxR) return minTree[treeIdx];
	ll mid = (dataIdxL + dataIdxR) / 2;
	return min(minQuery(queryL, queryR, 2 * treeIdx, dataIdxL, mid), minQuery(queryL, queryR, 2 * treeIdx + 1, mid + 1, dataIdxR));
}

// 최대트리
ll maxQuery(ll queryL, ll queryR, ll treeIdx, ll dataIdxL, ll dataIdxR) {
	if (queryL > dataIdxR || dataIdxL > queryR) return -1000000001;
	if (dataIdxL >= queryL && queryR >= dataIdxR) return maxTree[treeIdx];
	ll mid = (dataIdxL + dataIdxR) / 2;
	return max(maxQuery(queryL, queryR, 2 * treeIdx, dataIdxL, mid), maxQuery(queryL, queryR, 2 * treeIdx + 1, mid + 1, dataIdxR));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> node[i];

	minInit(node, 1, 1, n);
	maxInit(node, 1, 1, n);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << minQuery(a, b, 1, 1, n) << " " << maxQuery(a, b, 1, 1, n) << "\n";
	}

	return 0;
}
