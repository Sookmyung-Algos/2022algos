#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
#define ll long long
#define INF 1e9
using namespace std;

int ans = 987654321;
int ladder[31][11];  // ladder[h][n]
int n,m,h;

bool isManipulated() {
	for(int j=1;j<=n;++j) {
		int col = j;
		for(int i=1;i<=h;++i) {
			if(ladder[i][col]) col++;  // starting point, goes right
			else if(ladder[i][col-1]) col--;  // ending point, goes left

			// nothing happens, goes down
		}

		if(col != j) {
			return false;
		}
	}

	return true;
}

void dfs(int maxDepth,int cnt) {
	if(maxDepth == cnt) {
		if(isManipulated()) {
			printf("%d\n", maxDepth);  // 현재의 maxDepth에서는 최대값이자, 남은 maxDepth 후보 중에서는 최소값.
			// maxDepth가 0부터 시작하기 때문에 결국 최소값이 된다
			exit(0);
		}

		return;
	}

	for(int j=1;j<n;++j) {
		for(int i=1;i<=h;++i) {
			if(ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
			ladder[i][j] = 1;
			dfs(maxDepth,cnt+1);
			ladder[i][j] = 0;

			while(!ladder[i][j-1] && !ladder[i][j+1]) i++;  // skip rows until we can put a ladder
		}
	}

	return;
}


int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	scanf("%d%d%d", &n,&m,&h);
	for(int i=1;i<=m;++i) {
		int a,b;
		scanf("%d%d", &a, &b);

		ladder[a][b] = 1;
	}

	for(int i=0;i<4;++i) {
		dfs(i,0);
	}
	if(ans==987654321)
		ans = -1;

	printf("%d\n", ans);
	
	return 0;
}
