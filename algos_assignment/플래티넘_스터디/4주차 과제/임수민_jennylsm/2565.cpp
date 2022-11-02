#include <iostream>
#include <algorithm>
 
#define endl "\n"
#define MAX 110
using namespace std;
 
struct LINE
{
    int Left;
    int Right;
};
 
int N;
int DP[MAX];
LINE Line[MAX];
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Line[i].Left >> Line[i].Right;
    }
}
 
bool Cmp(LINE A, LINE B)
{
    if (A.Left < B.Left) return true;
    return false;
}
 
void Solution()
{
    int Correct_Line = 0;
    sort(Line + 1, Line + N + 1, Cmp);
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (Line[i].Right > Line[j].Right)
            {
                DP[i] = Max(DP[i], DP[j] + 1);
            }
        }
        Correct_Line = Max(Correct_Line, DP[i]);
    }
    cout << N - Correct_Line << endl;
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
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
