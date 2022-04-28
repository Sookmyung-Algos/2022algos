#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define MAX 1000000001

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[101][101];
int result = 100000;

int n,m;
char arr[101][101];
queue <tuple<int,int,int>> q;

int bfs(int x,int y, int cnt){
    q.push({x,y,cnt});
    
    while (!q.empty()){
        int nowx = get<0>(q.front());
        int nowy = get<1>(q.front());
        int nowcnt = get<2>(q.front());
        
        q.pop();
        if (nowx == n-1 && nowy == m-1)
            return nowcnt;
        
        for (int k=0;k<4;k++){
            int nextx = nowx+dx[k];
            int nexty = nowy+dy[k];
            
            if (nextx<0 || nexty<0 || nextx>=n || nexty>=m)
                continue;
            
            if (arr[nextx][nexty]=='1' && !visit[nextx][nexty]){
                visit[nextx][nexty]=true;
                q.push({nextx,nexty,nowcnt+1});
            }
        }
    }
    return 0;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    visit[0][0]=true;
    cout<<bfs(0,0,1);
}

