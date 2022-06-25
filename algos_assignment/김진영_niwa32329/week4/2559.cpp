#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n,k,tmp=0; 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	vector <int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i]; 
	}

	int max = -987654321; 
	

	for (int j = 0; j < k; j++) { 
		tmp += num[j]; 
	}
 

	for (int i = 0; i <=n-k; i++) { 
		if (tmp > max) max = tmp; 
		if (i + k >= n) break; 
		tmp += num[i + k];
		tmp -= num[i]; 
	}

	cout << max; 
	return 0; 
}
