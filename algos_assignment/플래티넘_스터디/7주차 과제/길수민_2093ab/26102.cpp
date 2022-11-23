#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 60;
const int MOD = 1e9 + 7;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int grundy[MAX][MAX][MAX][MAX];
vector<string> arr;
int N, M;

int solve (int lu, int ld, int ru, int rd)
{
    vector<bool> visited (MAX + MAX,false);
    if (grundy[lu][ld][ru][rd] != -1)
        return grundy[lu][ld][ru][rd];
    for (int i = lu; i <= rd; i += 2)
    {
        for (int j = ru; j <= ld; j += 2)
        {
            int x = i + j - M;
            if (M % 2) x++;
            x /= 2;
            int y = i - x;
            if (x < 0 || x >= N || y < 0 || y >= M)
                continue;
            int ret = 0;
            if (arr[x][y] == 'R')
            {
                if (i - 2 >= lu)
                    ret ^= solve (lu, ld, ru, i - 2);
                if (i + 2 <= rd)
                    ret ^= solve (i + 2, ld, ru, rd);
            }
            else if (arr[x][y] == 'B')
            {
                if (j - 2 >= ru)
                    ret ^= solve (lu, j - 2, ru, rd);
                if (j + 2 <= ld)
                    ret ^= solve (lu, ld, j + 2, rd);
            }
            else
            {
                if (i - 2 >= lu)
                {
                    if (j - 2 >= ru)
                        ret ^= solve (lu, j - 2, ru, i - 2);
                    if (j + 2 <= ld)
                        ret ^= solve (lu, ld, j + 2, i - 2);
                }
                if (i + 2 <= rd)
                {
                    if (j - 2 >= ru)
                        ret ^= solve (i + 2, j - 2, ru, rd);
                    if (j + 2 <= ld)
                        ret ^= solve (i + 2, ld, j + 2, rd);
                }
            }
            visited[ret] = true;
        }
    }
    for (int i = 0; i < MAX + MAX; i++)
    {
        if (!visited[i]) {
            return grundy[lu][ld][ru][rd] = i;
        }
    }
    return MAX + MAX - 1;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    memset(grundy, -1, sizeof(grundy));
    cin >> N >> M;
    arr.resize (N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int lu = 0;
    int rd = N + M - 2;
    if (rd % 2) rd--;
    int ld = N + M - 2;
    if (M % 2 == 0) ld++;
    if (ld % 2) ld--;
    int ru = 0;
    if (M % 2 == 0) ru = 2;
    int ret = solve (lu, ld, ru, rd);
    if (!(N == 1 && M == 1))
    {
        lu = 1;
        rd = N + M - 2;
        if (rd % 2 == 0) rd--;
        ld = N + M - 2;
        if (M % 2 == 0) ld++;
        if (ld % 2 == 0) ld--;
        ru = 1;
        ret ^= solve (lu, ld, ru, rd);
    }
    if (ret > 0) cout << "W\n";
    else cout << "L\n";
    return 0;
}

