#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> lst;
	list<char> ::iterator cur;
	char pStr, command;
	string s;
	int m;

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		lst.push_back(s[i]);
	}

	cur = lst.end();

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> command;

		if (command == 'L' && cur != lst.begin()) {
			cur--;
		}

		else if (command == 'D' && cur != lst.end()) {
			cur++;
		}

		else if (command == 'B' && cur != lst.begin()) {
			cur = lst.erase(--cur);
		}

		else if (command == 'P') {
			cin >> pStr;
			lst.insert(cur, pStr);
		}


	}

	for (list<char>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << *itr;
	}
	
	return 0;
}
