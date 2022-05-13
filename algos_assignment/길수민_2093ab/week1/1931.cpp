#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> time(N);
    for (int i = 0; i < N; i++)
        cin >> time[i].first >> time[i].second;
    sort(time.begin(), time.end(), compare);
    int cnt = 1;
    int cur = time[0].second;
    for (int i = 1; i < N; i++)
    {
        if (time[i].first >= cur)
        {
            cur = time[i].second;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
