#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000 + 1;
int n, m;

struct minimumTree{
	int n; //배열의 길이
	vector<long long> minTree;//각 구간의 최소치

	minimumTree(const vector<long long>& array) {
		n = array.size();
		minTree.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	//node 노드가 array[left...right] 배열을 표현할 때 node를 루트로 하는 서브트리 초기화
	long long init(const vector<long long>& array, int left, int right, int node) {
		if (left == right)	return minTree[node] = array[left];

		int mid = (left + right) / 2;
		long long leftSubTree = init(array, left, mid, node * 2);
		long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

		return minTree[node] = min(leftSubTree, rightSubTree);
	}
	
	//node가 표현하는 범위 array[nodeLeft...nodeRight]가 주어질 때 이 범위와 array[left...right]의 교집합
	long long query(int left, int right, int node, int nodeLeft, int nodeRight){
		if (right < nodeLeft || nodeRight < left) return INF; //두 구간이 겹치지 않는 경우
		if (left <= nodeLeft && nodeRight <= right)	return minTree[node]; //node가 표현하는 범위가 array[left...right]에 완전히 포함되는 경우

		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	long long query(int left, int right) {//query()를 외부에서 호출하기 위한 인터페이스
		return query(left, right, 1, 0, n - 1);
	}

	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {//array[index]=newValue로 바뀌었을 때 node를 루트로 하는 구간 트리 갱신
		if (index < nodeLeft || nodeRight < index) return minTree[node];//index가 노드가 표현하는 구간과 상관없는 경우
		if (nodeLeft == nodeRight)	return minTree[node] = newValue;//트리의 리프까지 내려온 경우

		int mid = (nodeLeft + nodeRight) / 2;
		return minTree[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}

	long long update(int index, int newValue) {//update()를 외부에서 호출하기 위한 인터페이스
		return update(index, newValue, 1, 0, n - 1);
	}
};

struct maximumTree{
	int n;//배열의 길이
	vector<long long> maxTree;//각 구간의 최소치

	maximumTree(const vector<long long>& array){
		n = array.size();
		maxTree.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	//node 노드가 array[left...right] 배열을 node를 루트로 하는 서브트리 초기화
	long long init(const vector<long long>& array, int left, int right, int node){
		if (left == right)	return maxTree[node] = array[left];
		int mid = (left + right) / 2;
		long long leftSubTree = init(array, left, mid, node * 2);
		long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

		return maxTree[node] = max(leftSubTree, rightSubTree);
	}

	//node가 표현하는 범위 array[nodeLeft...nodeRight]가 주어질 때 이 범위와 array[left...right]의 교집합
	long long query(int left, int right, int node, int nodeLeft, int nodeRight){
		if (right < nodeLeft || nodeRight < left)	return -1; //두 구간이 겹치지 않는 경우
		if (left <= nodeLeft && nodeRight <= right)	return maxTree[node];//node가 표현하는 범위가 array[left...right]에 완전히 포함되는 경우
	
		int mid = (nodeLeft + nodeRight) / 2;
		return max(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	long long query(int left, int right) {//query()를 외부에서 호출하기 위한 인터페이스
		return query(left, right, 1, 0, n - 1);
	}
	
	
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight) {//array[index]=newValue로 바뀌었을 때 node를 루트로 하는 구간 트리 갱신
		if (index < nodeLeft || nodeRight < index)	return maxTree[node];//index가 노드가 표현하는 구간과 상관없는 경우
		if (nodeLeft == nodeRight)	return maxTree[node] = newValue;//트리의 리프까지 내려온 경우

		int mid = (nodeLeft + nodeRight) / 2;
		return maxTree[node] = max(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	
	long long update(int index, int newValue) {//update()를 외부에서 호출하기 위한 인터페이스
		return update(index, newValue, 1, 0, n - 1);
	}
};

int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long num;
		cin	>> num;
		v.push_back(num);
	}

	minimumTree minTree(v);
	maximumTree maxTree(v);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << minTree.query(a - 1, b - 1) << " " << maxTree.query(a - 1, b - 1) << "\n";
	}
	return 0;
}
