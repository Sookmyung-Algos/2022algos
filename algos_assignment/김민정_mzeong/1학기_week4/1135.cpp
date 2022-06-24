#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[50];

int dfs(int cur) {
    if (v[cur].empty()) return 0;

    vector<int> s;
    for (int next : v[cur]) {
        s.push_back(dfs(next));
    }
    sort(s.begin(), s.end(), greater<int>());
    
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret = max(ret, s[i] + (i+1));
    }
    return ret;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (num == -1) continue;
        v[num].push_back(i);
    }
    cout << dfs(0);
    
    return 0;
}
