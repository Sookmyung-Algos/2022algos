#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;	
	int m;	
	list<char> chlist;	
	char input;	
	char temp;	

	cin >> str;
	cin >> m;

	for (int i = 0; i < str.length(); i++)	
		
	list<char>::iterator it = chlist.end();	


	for (int i = 0; i < m; i++)	
	{
		cin >> input;	

		if (input == 'P')	
		{
			cin >> temp;	
			chlist.insert(it, temp);	
		}
		else if (input == 'L')
		{
			if(it!=chlist.begin())	
				it--;	
		}
		else if (input == 'D')
		{
			if (it != chlist.end())	
				it++;	
		}
		else if (input == 'B')
		{
			if (it != chlist.begin())	
			{
				it = chlist.erase(--it);	
			}
		}

	}

	for (it = chlist.begin(); it != chlist.end(); it++)	
		cout << *it;


	return 0;
}
