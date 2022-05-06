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

int arr[51][51];
bool visit[51][51];

int n,l,r;
int result=0;
int cnt,sum;
vector <pair <int,int>> v;

int dy[4] = {1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void dfs(int y, int x) {

    for (int i = 0; i < 4; i++) {
        int nexty = y + dy[i];
        int nextx = x + dx[i];

        if (!visit[nexty][nextx]) {
            if (nexty>=0 && nexty<n && nextx>=0 && nextx<n) {
                if (abs(arr[y][x]-arr[nexty][nextx])>=l && abs(arr[y][x]-arr[nexty][nextx]) <= r) {
                    visit[nexty][nextx] = 1;
                    cnt++;
                    sum += arr[nexty][nextx];
                    v.push_back({nexty, nextx});
                    dfs(nexty, nextx);
                }
            }
        }
    }
}


int main() {
    cin>>n>>l>>r;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    
    while (1){
        bool flag=false;
        memset(visit,false,sizeof(visit));
        
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (!visit[i][j]){
                    v.clear();
                    cnt=1;
                    sum=arr[i][j];
                    visit[i][j]=1;
                    
                    v.push_back({i,j});
                    dfs(i,j);
                    if (cnt>=2){
                        flag=true;
                        for (int k=0;k<v.size();k++){
                            arr[v[k].first][v[k].second]=sum/cnt;
                        }
                    }
                }
            }
        }
        if (flag == false)
            break;
        else
            result++;
    }
    cout<<result;

}
