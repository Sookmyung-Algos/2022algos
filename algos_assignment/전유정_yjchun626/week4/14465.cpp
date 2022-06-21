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
    
 	// map배열을 false값으로 초기화
	memset(map, false, sizeof(map));
    
	cin >> n >> k >> b;
	
	// b개의 고장난 신호등의 인덱스를 받아, map이라는 변수에 고장났다면 true로 갱신
	for (int i = 1; i <= b; i++) 
	{
		cin >> now;
		map[now] = true;
	}
	int cnt = 0;
    
	// 1번 신호등부터 K번 신호등까지 몇개가 고장났는지 확인.
	for (int i = 1; i <= k; i++)
		cnt += map[i];
	ans = cnt;
	
	int j = 1;
	for (int i = k + 1; i <= n; i++)
	{
    	// 인덱스를 하나씩 밀어가며, 슬라이딩 윈도우의 가장 앞, 뒤만을 갱신하여 빠른 처리.
		cnt += map[i];
		cnt -= map[j++];
		ans = min(ans, cnt);
	}
    
	cout << ans << '\n';
}
