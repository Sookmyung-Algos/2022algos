#include<iostream>
#include<vector>
 
#define endl "\n"
#define MAX 401
using namespace std;
 
int N, K, S;
int MAP[MAX][MAX];
vector<pair<int, int>> Want;
 
void Input()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = -1;
        MAP[b][a] = 1;
    }
    cin >> S;
    for (int i = 0; i < S; i++)
    {
        int a, b;
        cin >> a >> b;
        Want.push_back(make_pair(a, b));
    }
}
 
void Solution()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (MAP[i][j] == 0)
                {
                    if (MAP[i][k] == 1 && MAP[k][j] == 1)
                    {
                        MAP[i][j] = 1;
                    }
                    else if (MAP[i][k] == -1 && MAP[k][j] == -1)
                    {
                        MAP[i][j] = -1;
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < Want.size(); i++)
    {
        int a = Want[i].first;
        int b = Want[i].second;
 
        cout << MAP[a][b] << endl;
    }
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
