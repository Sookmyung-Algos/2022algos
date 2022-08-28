#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> map[50];
vector<int> friends_cnt;
int N;

int main() {
	cin >> N;
	char temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 'Y') {
				map[i].push_back(j);
			}
		}
	}
	unordered_set<int> friends;
	for (int i = 0; i < N; i++) {
		for (auto &ele : map[i]) {
			friends.insert(ele);
			for (auto &f : map[ele]) {
				if (f != i) friends.insert(f);
			}
		}
		friends_cnt.push_back(friends.size());
		friends.clear();
	}
	sort(friends_cnt.begin(), friends_cnt.end());
	cout << friends_cnt[N-1];
}
