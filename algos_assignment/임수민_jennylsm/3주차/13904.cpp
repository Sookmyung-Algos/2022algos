#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
int d, w;
pair<int, int> arr[1000];
int due[1001];
int result;
 
class cmp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second ? true : false;
    }
};
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    cin >> N;
    for (int i = 0; i < N; i++)    cin >> arr[i].first >> arr[i].second;
    
    // 점수 내림차순 정렬
    sort(arr, arr + N, cmp());
 
    // 가장 높은 점수부터 연기할 수 있을 만큼 연기함, 만약 불가능하면 그 점수는 포기
    for (int i = 0; i < N; i++)
    {
        int index = arr[i].first;
        if (!due[index]) due[index] = arr[i].second;
        else
        {
            while (due[--index]);
            if (index != 0) due[index] = arr[i].second;
        }
    }
 
    for (int i = 1; i < 1001; i++) result += due[i];
    cout << result;
 
    return 0;
}
