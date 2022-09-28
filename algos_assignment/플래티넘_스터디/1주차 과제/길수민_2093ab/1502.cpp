#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

vector<vector<int>> map;
vector<pi> path;
int cnt, m, n;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool backtrack (int cur_x, int cur_y)
{
    path.push_back ({cur_x + 1, cur_y + 1});
    cnt--;
    if (cnt == 0 && map[cur_x][cur_y] == 2)
    {
        cout << "1\n";
        for (auto& it : path)
            cout << it.first << " " << it.second << "\n";
        return true;
    }
    else if (cnt == 0)
        return false;
    for (int i = 0; i < 4; i++)
    {
        int next_x = cur_x + dx[i];
        int next_y = cur_y + dy[i];
        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
            continue;

        if (map[next_x][next_y] == 0)
        {
            map[next_x][next_y] = 3;
            if (backtrack (next_x, next_y))
                return true;
            map[next_x][next_y] = 0;
        }
        if (map[next_x][next_y] == 2)
        {
            if (cnt != 1) continue;
            return backtrack (next_x, next_y);
        }

    }
    path.pop_back();
    cnt++;
    return false;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int i, j, a, b;
        cin >> m >> n;
        cin >> i >> j;
        cin >> a >> b;
        cnt = m * n;
        map.assign (m, vector<int> (n, 0));
        vector<pi>().swap(path);
        map[i - 1][j - 1] = 2;
        map[a - 1][b - 1] = 1;
        bool oddFirst = (i + j) % 2;
        bool oddSecond = (a + b) % 2;

        if ((cnt % 2) && oddFirst != oddSecond)
            cout << "-1\n";
        else if ((cnt % 2 == 0) && oddFirst == oddSecond)
            cout << "-1\n";
        else if (!backtrack (a - 1, b - 1))
            cout << "-1\n";
    }
    return 0;
}
