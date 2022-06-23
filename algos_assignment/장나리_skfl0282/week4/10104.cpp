#include<iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k,m;
	list<int> l;
	cin >> k >> m;
	
	for (int i = 0; i < k; i++) {
		l.push_back(i + 1);
	}
    std::list<int>::iterator a;
    while (m--)
    {
        int r, i = 1;
        cin >> r;
        a = l.begin();
        while (a != l.end())
        {
            if (i % r == 0)
            {
                a = l.erase(a++);
            }
            else
                a++;
            i++;
        }
    }
    for (auto a = l.begin(); a != l.end(); a++)
    {
        cout << *a << "\n";
    }
	return 0;
}
