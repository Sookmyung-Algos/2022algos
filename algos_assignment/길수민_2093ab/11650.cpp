#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort (arr.begin(), arr.end());
    for (auto pos : arr)
        cout << pos.first << " " << pos.second << "\n";
    return 0;
}
