#include<iostream>
 
#define endl "\n"
#define MAX 1001
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];    // 앞에서부터 찾는 최장수열
int R_DP[MAX];    // 뒤에서부터 찾는 최장수열
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
    }
}
 
void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (Arr[j] < Arr[i] && DP[i] < DP[j] + 1)
            {
                DP[i] = DP[j] + 1;
            }
        }
    }
 
    for (int i = N; i >= 1; i--)
    {
        R_DP[i] = 1;
        for (int j = N; j >= i; j--)
        {
            if (Arr[i] > Arr[j] && R_DP[j] + 1 > R_DP[i])
            {
                R_DP[i] = R_DP[j] + 1;
            }
        }
    }
 
    int Answer = 0;
    for (int i = 0; i <= N; i++)
    {
        if (Answer < DP[i] + R_DP[i] - 1) Answer = DP[i] + R_DP[i] - 1;
    }
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
//    freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
