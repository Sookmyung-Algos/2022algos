
#include <iostream>
#include <vector>
#include <queue>

#define MAX 9876543210

using namespace std;

struct info {
	int idx;
	long long val;
};

info tmp;
vector<info> v[501];
long long dist[501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
	int test, node, edge, warmhole, s, e;
	long long val;
	cin >> test;
  
	for (int t = 0; t < test; t++) {
		cin >> node >> edge >> warmhole;
    
		for (int i = 1; i <= node; i++) {
			v[i].clear();
			dist[i] = MAX;
		}
    
		for (int i = 0; i < edge; i++) {
			cin >> s >> e >> val;
			tmp.val = val;
			tmp.idx = e;
			v[s].push_back(tmp);
			tmp.idx = s;
			v[e].push_back(tmp);
		}
    
		for (int i = 0; i < warmhole; i++) {
			cin >> s >> e >> val;
			tmp.idx = e;
			tmp.val = -val;
			v[s].push_back(tmp);
		}
    
		bool cycle = false;
		for (int i = 1; i <= node; i++) {
			for (int j = 1; j <= node; j++) {
				int from = j;
        
				for (int k = 0; k < v[from].size(); k++) {
					int next = v[from][k].idx;
					int nv = v[from][k].val;
          
					if (dist[next] > dist[from] + nv) {
						dist[next] = dist[from] + nv;
						if (i == node) {
							cycle = true;
							break;
						}
					}
				}
				if (cycle) break;
			}
			if (cycle) break;
		}
		if (cycle) cout << "YES\n";
		else cout << "NO\n";
	}
	system("pause");
	return 0;
}
