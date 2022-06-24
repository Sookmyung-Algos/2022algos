#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <memory.h>
 
#define INF 1000000007
 
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
 
int n;
vector<int> adj[51];
 
bool cmp(int a, int b) {
    return a > b;
}
 
int get_time(int node, int pnode) {
    int ret = 0;
    vector<int> res;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        res.push_back(get_time(child, node));
    }
 
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++) {
        ret = max(ret, res[i] + i + 1);
    }
   
    return ret;
}
 
void init() {
    int parent;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent == -1) continue;
        adj[parent].push_back(i);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
 
    init();
    int ans = get_time(0, -1);
    cout << ans << "\n";
    return 0;
}
 
