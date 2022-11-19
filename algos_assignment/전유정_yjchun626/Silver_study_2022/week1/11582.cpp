#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // 처리 시간 단축
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, grd; // 치킨 개수, 치킨 맛 수치
	cin >> n;  // 치킨 개수 n개 입력
	vector<int>v;
	
    for (int i = 0; i < n; i++) {  // n만큼 반복
		cin >> grd;
		v.push_back(grd); // 벡터 v에 치킨 맛 수치 grd를 저장
	}
	
    int mems;  // 전체 회원 수 mems - mems명의 회원이 정렬을 할 때 정렬 중지
    cin >> mems;  // 전체 회원 수 입력
	
	int mrg = n / 2;  // 현재 정렬(merge)하는 사람의 수 mrg
    
	while (mrg >= 1) {
		
		int mrsize = n / mrg; // 한 번에 몇 칸씩 합병하는지 그 크기
		for (int i = 0; i < n - 1; i = i + mrsize) { 
			sort(v.begin() + i, v.begin() + i + mrsize);
            // i번째부터 (i+mrsize)번째까지 오름차순 정렬 - 한 번에 합병하는 만큼
		}

		if (mrg == mems) {  // 정렬하는 사람 수가 전체 사람 수와 같은 경우
			for (int i = 0; i < n; i++) cout << v[i] << ' '; // 벡터 출력
			cout << '\n';
			break;  // 그대로 break - 정렬 더 이어갈 필요 없기 때문에
		}

		mrg = mrg / 2; 
        // n/2, n/4, n/8... 명이 정렬하도록 함
	}
}
