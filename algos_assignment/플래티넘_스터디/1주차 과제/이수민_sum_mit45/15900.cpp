#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N;
int cnt=0;
bool check[500001];
vector<int> tree[500001];
queue<int> q;

void dfs(int x, int depth){
    if (x != 1 && tree[x].size() == 1){ // 연결된 노드 하나일 때 -> 리프노드
        if (depth % 2 == 1) cnt++;
        return;
    }

    for (int i = 0; i < tree[x].size(); i++){
        if (check[x] == false){
            check[x] = true;
            dfs(tree[x][i], depth + 1);
            check[x] = false;
        }
    }
}

int main(){
    cin >> N;

    for (int i = 0; i<N-1; i++){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, 0);

    if (cnt % 2 == 1) cout << "Yes";
    else cout << "No";
}
