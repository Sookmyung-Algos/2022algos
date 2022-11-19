#include <iostream>
#include <vector>
#define MAX 1000010
using namespace std;

int N;
int arr[MAX];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (v.back() < arr[i]) {
			v.push_back(arr[i]);
		}
		else {
			auto itr = lower_bound(v.begin(), v.end(), arr[i]);
			*itr = arr[i];
		}
	}
	cout << v.size();
	return 0;
}
