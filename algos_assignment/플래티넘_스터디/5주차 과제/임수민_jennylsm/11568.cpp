#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int n, arr[1001];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    //freopen("input.txt", "r", stdin);
 
    cin >> n;
 
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
 
    vector<int> ans;
    const int INF = 1e9;
    ans.push_back(-INF); // 절대적으로 작은 수 하나 삽입
 
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] > ans.back())
            ans.push_back(arr[i]);
        else
        {
            // arr[i]가 들어갈 위치 찾기
            vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), arr[i]);
            *it = arr[i];
        }
    }
 
    cout << ans.size() - 1 << endl; // 처음 삽입한 -INF 제거
 
    return 0;
}
