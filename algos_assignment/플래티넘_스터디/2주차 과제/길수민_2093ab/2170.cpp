#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    vector<pi> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort (arr.begin(), arr.end());
    int ans = 0;
    int start = arr[0].first;
    int end = arr[0].second;
    for (auto& it : arr)
    {
        if (it.first <= end)
            end = max (end, it.second);
        else
        {
            ans += end - start;
            start = it.first;
            end = it.second;
        }
    }
    ans += end - start;
    cout << ans << "\n";

    return 0;
}
