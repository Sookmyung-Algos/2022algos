#include <iostream>
 
#define endl "\n"
#define MAX 1010
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];
 
int Max(int A, int B) { if (A > B) return A; return B; }

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> Arr[i];
    
    int Answer = 0;
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (Arr[i] > Arr[j])
            {
                DP[i] = Max(DP[i], DP[j] + 1);
            }
        }
        Answer = Max(DP[i], Answer);
    }
 
    cout << Answer << endl;
 
    return 0;
}
