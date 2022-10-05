#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N, k;
    cin >> N >> k;
    vector<int> line(k, 0);
    bool res = true;
    for (int i = 0; i < N; i++)
    {
        int cur;
        bool check = false;
        cin >> cur;
        if (!res) continue;
        for (int j = 0; j < k; j++)
        {
            if (line[j] < cur)
            {
                check = true;
                line[j] = cur;
                break;
            }
        }
        if (!check)
            res = false;
    }
    if (res) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
