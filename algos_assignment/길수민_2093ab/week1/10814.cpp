#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<pair<int, string>> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        arr.push_back({age, name});
    }
    stable_sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < N; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
    return 0;
}
