#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int N, M, S, K;
int d[MAX], c[MAX];
vector<int> a[MAX];

bool dfs(int x){
	for(int i = 0; i < a[x].size(); i++){
		int temp = a[x][i];
		if(c[temp]) continue;
		c[temp] = true;
		if(d[temp] == 0 || dfs(d[temp])){
			d[temp] = x;
			return true;
		}
	}
	return false;
}

int main(void){
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		int x, y;
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> y;
			a[i].push_back(y);
		}
	}
	int count = 0;
	for(int i = 1; i <= N; i++){
		fill(c, c + MAX, false);
		if(dfs(i)) count++;
	}
	int extra = 0;
	for(int i = 1; i <= N && extra < K; i++){
		fill(c, c + MAX, false);
		if(dfs(i)) extra++;
	}
	cout << count + extra;
	return 0;
}
