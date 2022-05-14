#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int re = 50;
string in, stand;

int main()
{
	cin >> in >> stand;

	for (int i = 0; i <=(stand.length() - in.length()); i++) 
    {
		int count = 0;
		for (int j = 0; j < in.length(); j++) 
        {
			if (in[j] != stand[j+i]) 
            {
				count++;
			}
		}
		re = min(re, count);
	}
	cout << re;

	return 0;
 
}
