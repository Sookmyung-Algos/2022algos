#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n, cur_i, cur_j;
ll ans;
int arr[10][10][10][10];
vector<pipi> parent_set;
vector<int> cur;
int flag[4];

void backtrack (int step, int prev, bool positive)
{
    if (cur.size() == step)
    {
        int tmp[2][4] = {{flag[0], flag[1], flag[2], flag[3]}, {-1, -1, -1, -1}};
        for (auto& it : cur)
        {
            if (it == 0) {
                tmp[0][it] = parent_set[cur_i].first.first;
                tmp[1][it] = parent_set[cur_j].first.first;
            } else if (it == 1) {
                tmp[0][it] = parent_set[cur_i].first.second;
                tmp[1][it] = parent_set[cur_j].first.second;
            } else if (it == 2) {
                tmp[0][it] = parent_set[cur_i].second.first;
                tmp[1][it] = parent_set[cur_j].second.first;
            } else {
                tmp[0][it] = parent_set[cur_i].second.second;
                tmp[1][it] = parent_set[cur_j].second.second;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            if (tmp[i][0] == -1) continue;
            for (int j = 0; j < 2; j++)
            {
                if (tmp[j][1] == -1) continue;
                for (int k = 0; k < 2; k++)
                {
                    if (tmp[k][2] == -1) continue;
                    for (int l = 0; l < 2; l++)
                    {
                        if (tmp[l][3] == -1) continue;
                        if (positive) ans += arr[tmp[i][0]][tmp[j][1]][tmp[k][2]][tmp[l][3]];
                        else ans -= arr[tmp[i][0]][tmp[j][1]][tmp[k][2]][tmp[l][3]];
                    }
                }
            }
        }
        return;
    }
    for (int i = prev + 1; i < 4; i++)
    {
        if (flag[i] == 0) {
            cur.push_back (i);
            backtrack (step, i, positive);
            cur.pop_back();
        }
    }
    return;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n;
    parent_set.resize (n);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        int first = num / 1000;
        num %= 1000;
        int second = num / 100;
        num %= 100;
        int third = num / 10;
        num %= 10;
        arr[0][0][0][0]++;
        arr[first][0][0][0]++;
        arr[0][second][0][0]++;
        arr[0][0][third][0]++;
        arr[0][0][0][num]++;
        arr[first][second][0][0]++;
        arr[first][0][third][0]++;
        arr[first][0][0][num]++;
        arr[0][second][third][0]++;
        arr[0][second][0][num]++;
        arr[0][0][third][num]++;
        arr[first][second][third][0]++;
        arr[first][second][0][num]++;
        arr[first][0][third][num]++;
        arr[0][second][third][num]++;
        arr[first][second][third][num]++;
        parent_set[i] = {{first, second}, {third, num}};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cur_i = i;
            cur_j = j;
            flag[0] = parent_set[i].first.first == parent_set[j].first.first;
            flag[1] = parent_set[i].first.second == parent_set[j].first.second;
            flag[2] = parent_set[i].second.first == parent_set[j].second.first;
            flag[3] = parent_set[i].second.second == parent_set[j].second.second;
            if (flag[0]) flag[0] = parent_set[i].first.first;
            if (flag[1]) flag[1] = parent_set[i].first.second;
            if (flag[2]) flag[2] = parent_set[i].second.first;
            if (flag[3]) flag[3] = parent_set[i].second.second;
            ans += arr[flag[0]][flag[1]][flag[2]][flag[3]];
            bool positive = false;
            for (int k = 1; k <= 4; k++)
            {
                backtrack (k, -1, positive);
                positive = !positive;
            }
        }
    }
    cout << ans / 3 << "\n";
    return 0;
}
