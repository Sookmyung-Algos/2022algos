#include <iostream>
#include <algorithm>
#include <list>
using namespace std; 

int k, m; 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >>k>>m;
	list<int> lst; 

	for (int i = 0; i < k; i++) {
		lst.push_back(i + 1); 
	}

	std::list<int>::iterator it; //list 반복자 it 선언 
	for (int i = 0; i < m; i++) {
		int r = 1,j = 1; 
		cin >> r; 
		it = lst.begin(); 

		while (it != lst.end()) {
			if (j % r == 0) it = lst.erase(it++);
			else it++;
			j++; 
		}
	}

	for (it = lst.begin(); it != lst.end(); it++) {
		cout << *it << "\n"; 
	}
	
}
