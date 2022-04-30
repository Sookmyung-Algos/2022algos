#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
int n; 
int c = 1;

//오름차순 정렬
bool compare(pair<int, int>v1, pair<int, int> v2) 
{
	if(v1.second == v2.second) 
		return v1.first < v2.first;
  else
	  return v1.second < v2.second;
}

int main(void) 
{
	int start, end; 
	int from, to; 
	
	cin >> n;

	for (int i = 0; i < n; i++) 
  {
		scanf("%d %d", &start, &end);
		v.push_back(pair<int, int>(start, end));
	}

	sort(v.begin(), v.end(), compare); 
	
	from = v[0].second; 
	for(int i = 1; i < n; i++) 
  {
		to = v[i].first;
		if(from <= to) {
			c++;
			from = v[i].second;
		}
	}
	cout << c;
}
