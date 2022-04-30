#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp (pair<int, string> u, pair<int, string> v)
{
    return u.first < v.first;
}

int main()
{
    int T;
    cin >> T;

    vector<pair<int, string>> vec(T);

    for (int i = 0; i < T; i++)
        cin >> vec[i].first >> vec[i].second;

    stable_sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < T; i++)
        cout << vec[i].first << " " << vec[i].second << "\n";
}
