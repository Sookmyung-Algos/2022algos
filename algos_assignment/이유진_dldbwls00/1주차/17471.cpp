#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

const int MAX = 10;
const int INF = 987654321;

int n;
int result;
int villagers[MAX];
vector<int> v;
vector<int> neighbors[MAX];

bool isAllVillagesConnected(vector<int> zone){
	bool visited[MAX] = { false, };

	queue<int> q;
	q.push(zone[0]);
	visited[zone[0]] = true;

	while (!q.empty()){
		int cur = q.front();
		q.pop();

		for (int i = 0; i < neighbors[cur].size(); i++){
			int next = neighbors[cur][i];
			vector<int>::iterator it = find(zone.begin(), zone.end(), next);

			if (it == zone.end()) continue;
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}

	for (int i = 0; i < zone.size(); i++){
		if (visited[zone[i]] == false) return false;
	}
	return true;
}

void func(void){
	vector<int> reds, blues;

	for (int i = 0; i < v.size(); i++) v[i] == 0 ? reds.push_back(i) : blues.push_back(i);
	if (isAllVillagesConnected(reds) == false || isAllVillagesConnected(blues) == false) return;

	int temp = 0;
	for (int i = 0; i < reds.size(); i++) temp += villagers[reds[i]];
	for (int i = 0; i < blues.size(); i++) temp -= villagers[blues[i]];
	result = min(result, abs(temp));
}

int main(void){
	cin >> n;

	for (int i = 0; i < n; i++) cin >> villagers[i];
	for (int i = 0; i < n; i++){
		int num;
		cin >> num;

		for (int j = 0; j < num; j++){
			int neighbor;
			cin >> neighbor;
			neighbors[i].push_back(neighbor - 1);
		}
	}

	result = INF;

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++) v.push_back(0);
		for (int j = 0; j < n - i; j++) v.push_back(1);

		do{
			func();
		} while (next_permutation(v.begin(), v.end()));
		v.clear();
	}

	if (result == INF) cout << -1 << "\n";
	else cout << result << "\n";
	return 0;
}
