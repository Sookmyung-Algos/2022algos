#include<iostream>
#include<cstring>
#include<queue>

#define endl "\n"
#define MAX 100
using namespace std;

int N, M;
int MAP[MAX][MAX];


void Solution()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j) continue;
                else if (MAP[i][k] != 0 && MAP[k][j] != 0)
                {
                    if (MAP[i][j] == 0) MAP[i][j] = MAP[i][k] + MAP[k][j];
                    else MAP[i][j] = min(MAP[i][j], MAP[i][k] + MAP[k][j]);
                }
            }
        }
    }
}

int MinPerson()
{
    int Result = 999999;
    int Person = 1;
    for (int i = 1; i <= N; i++)
    {
        int Tmp_Result = 0;
        for (int j = 1; j <= N; j++)
        {
            Tmp_Result = Tmp_Result + MAP[i][j];
        }

        if (Result > Tmp_Result)
        {
            Result = Tmp_Result;
            Person = i;
        }
    }
    return Person;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }
    Solution();
    int Answer = MinPerson();

    cout << Answer << endl;
}
