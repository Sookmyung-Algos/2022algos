// 복습 필요
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;

struct segmentTree{
	int n; //배열의 길이
	vector<long long> pSum; //각 구간의 부분합
	segmentTree(const vector<long long>& array){
		n = array.size();
		pSum.resize(n * 4);
		init(array, 0, n - 1, 1); //array[left..right]배열 표현
	}

	//node를 루트로 하는 서브트리 초기화

	long long init(const vector<long long>& array, int left, int right, int node){
		if (left == right)	return pSum[node] = array[left];

		int mid = (left + right) / 2;
		long long leftSubTree = init(array, left, mid, node * 2);
		long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

		return pSum[node] = leftSubTree + rightSubTree;
	}

	//node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때
	//이 범위와 array[left..right]의 교집합
	long long query(int left, int right, int node, int nodeLeft, int nodeRight){
		if (right < nodeLeft || nodeRight < left)	return 0; //두 구간이 겹치지 않는 경우
		if (left <= nodeLeft && nodeRight <= right)	return pSum[node]; //node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
		
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	long long query(int left, int right){
		return query(left - 1, right - 1, 1, 0, n - 1);
	}

	//array[index]=newValue로 바뀌었을 때 node를 루트로하는 구간트리 갱신
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight){
		if (index < nodeLeft || nodeRight < index) return pSum[node];
		if (nodeLeft == nodeRight) return pSum[node] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;
		return pSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}

	long long update(int index, int newValue){
		return update(index - 1, newValue, 1, 0, n - 1);
	}
};

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> q;

	vector<long long> v(n);

	for (int i = 0; i < n; i++)	cin >> v[i];

	segmentTree seg(v);

	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		cin	>> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << seg.query(x, y) << "\n";

		seg.update(a, b);
		v[a - 1] = b;
	}
	return 0;
}
