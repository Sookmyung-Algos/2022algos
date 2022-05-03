#include <iostream>
#include <stack>
using namespace std;
int a_arr[1000005];
int b_arr[1000005];
int c_arr[2000010];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	
	
	for (int i = 0; i < a; i++) {
		cin >> a_arr[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> b_arr[i];
	}
	
	int a_id = 0;
	int b_id = 0;
	int c_id = 0;

	while (c_id < a + b) {
		if (a_id == a) {
			c_arr[c_id++] = b_arr[b_id++];
		}
		else if (b_id == b) {
			c_arr[c_id++] = a_arr[a_id++];
		}
		else if (a_arr[a_id] < b_arr[b_id]) {
			c_arr[c_id++] = a_arr[a_id++];
		}
		else {
			c_arr[c_id++] = b_arr[b_id++];
		}
	}
	
	for (int i = 0; i < a + b; i++) {
		cout << c_arr[i] << ' ';
	}
	

}
