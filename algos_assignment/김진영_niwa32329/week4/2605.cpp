#include <iostream>
#include <vector>
using namespace std; 

int n; 
vector<int> v; 
 

int main() {
	cin >> n; 
	for (int i = 1; i <=n; i++) {
		int temp; 
		cin >> temp; 
		v.insert(v.begin() + temp, i); 
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}

	return 0; 

}
