#include<iostream>
#include<vector>
using namespace std;

vector<int> a[101];
bool chk[101];
int cnt = 0;

void DFS(int x){
    chk[x] = true;
    for (int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        if (!chk[y]){
            DFS(y);
            cnt++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    cout << cnt << '\n';
}
