#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101]; 
bool check[101];
int cnt = 0;

void dfs(int x);
int main() {
	int n, pair;
	cin >> n >> pair;
	for (int i = 0; i < pair; i++) { //edge 연결
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << cnt << '\n';
}
void dfs(int x) {
	check[x] = true; //초기화
	for (int i = 0; i < v[x].size(); i++) {
		int num = v[x][i];
		if (!check[num]) {
			dfs(num);
			cnt++;
		}
	}
}
