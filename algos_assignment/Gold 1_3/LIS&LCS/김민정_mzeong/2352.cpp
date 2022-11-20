#include <bits/stdc++.h>
using namespace std;

int arr[40001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    for (int i = 1; i <= n; i++) {
        if (v.size() == 0 || v[v.size() - 1] < arr[i]) v.push_back(arr[i]);
        else {
            int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[pos] = arr[i];
        } 
    }
    cout << v.size();
    return 0;
}
