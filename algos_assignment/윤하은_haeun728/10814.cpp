#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> x, pair<int, string> y)
{
    return x.first < y.first;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int age;
    string name;
    vector<pair<int, string>> vp_sort;
    for (int i = 0; i < N; i++)
    {
        cin >> age >> name;

        vp_sort.push_back({age, name});
    }

    stable_sort(vp_sort.begin(), vp_sort.end(), compare);

    for (int i = 0; i < N; i++)
        cout << vp_sort[i].first << " " << vp_sort[i].second << '\n';

    return 0;
}
