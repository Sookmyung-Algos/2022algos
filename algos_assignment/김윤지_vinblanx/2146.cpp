#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
#define MAX 101

using namespace std;

int arr[MAX][MAX];
int n = 0, ans = 1e9;
int my[] = {1,-1,0,0}, mx[] = {0,0,1,-1};
int ny, nx, yy, xx;
vector<pair<int,int>> v;

void distance_circulate(){
    int temp = 0;
    for(int i = 0; i < v.size() - 1; i++){
        yy = v[i].first;
        xx = v[i].second;
        for(int j = i + 1; j < v.size(); j++){
            ny = v[j].first;
            nx = v[j].second;
            if(arr[yy][xx] > 0 && arr[ny][nx] > 0 && arr[yy][xx] != arr[ny][nx]){
                temp = abs(yy-ny) + abs(xx-nx)-1;
                if(ans > temp) ans = temp;
            }
        }
    }
}

void label_land(int y, int x, int idx){
    queue<pair<int,int>> q;
    q.push({y,x});
    while(!q.empty()){
        bool edge = false;
        yy = q.front().first;
        xx = q.front().second;
        arr[yy][xx] = idx;
        q.pop();
        for(int i = 0; i < 4; i++){
            ny = yy + my[i];
            nx = xx + mx[i];
            if(ny > 0 && ny <= n && nx > 0 && nx <= n && arr[ny][nx] < 0){
                arr[ny][nx] = idx;
                q.push({ny,nx});
            }
            else if(ny > 0 && ny <= n && nx > 0 && nx <= n && arr[ny][nx] == 0){
                edge = true;
            }
        }
        if(edge) v.push_back({yy, xx});
    }
}

void input(){
    int label = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(arr[i][j] != 0) arr[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] < 0){
                label_land(i, j, label++);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    distance_circulate();
    cout << ans << "\n";
    return 0;
}
