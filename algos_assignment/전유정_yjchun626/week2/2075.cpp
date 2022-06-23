#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2250010];  // n^2의 최고 값은 2,250,000
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  // 시간 초과 방지 위해 추가하는 구문

    int n;  // n번째 큰 수 찾기
    cin >> n;  // n 입력
    for (int i = 0; i < n*n; i++)  // n^2 만큼 반복
    {
        cin >> arr[i];  // 배열 입력
    }
    
    sort(arr, arr + n*n);  // 모든 수 정렬
    cout << arr[n*n - n] << endl;  // n번째 큰 수 출력
    
    return 0;
}
