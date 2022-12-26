#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 100001;

int n, b, k;
bool map[MAX];

int main()
{ 
	int now;
	int ans = 100000;
    
	memset(map, false, sizeof(map));
    
	cin >> n >> k >> b;
	
	for (int i = 1; i <= b; i++) 
	{
		cin >> now;
		map[now] = true;
	}
	int cnt = 0;
    
	// 몇 개 고장났는지 개수 확인
	for (int i = 1; i <= k; i++)
		cnt += map[i];
	ans = cnt;
	
	int j = 1;
	for (int i = k + 1; i <= n; i++)
	{
		cnt += map[i];
		cnt -= map[j++];
		ans = min(ans, cnt);
	}
    
	cout << ans << '\n';
}
