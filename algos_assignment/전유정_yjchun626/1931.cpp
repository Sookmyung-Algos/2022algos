#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n, begin, end;
    int count = 1;
	  cin >> n;
	  vector<pair<int, int>> value;  // 시작 시간, 끝나는 시간 입력 받음
    
    for (int i = 0; i < n; i++) {
		cin >> begin >> end;
		value.push_back(make_pair(end, begin));
        // push_back : vector의 끝에 요소 추가
        // make_pair(변수1, 변수2) : 변수1, 변수2를 하나로 묶은 pair 생성
	  }
    sort(value.begin(), value.end());
    
    int time = value[0].first;
	  for (int i = 1; i < n; i++) 
	  {
		  if (time <= value[i].second )
		  {
			  count++;
			  time = value[i].first;
		  }
	  }
    cout << count;
}
