#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>

#define INF 1e9

using namespace std;

int n, m, t, d;

char map[30][30];
int graph[30][30];

//시간을 저장
int dist[30][30];
int visited[30][30];

//하산 시 걸리는 시간...
int re[30][30];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int sum = 0;


int change_int(char a){
    if('A' <= a && 'Z' >= a ){
        return a - 'A';
    }
    return a - 'a' + 26;
}

void bfs(){
    //time은 적을 수록  x, y;
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>>q;
    
    q.push({{0, -graph[0][0]}, {0, 0}});
    visited[0][0] = 1;
    dist[0][0] = 0;
    
    while(!q.empty()){
        
        int time = q.top().first.first;

        int x = q.top().second.first;
        int y = q.top().second.second;
        
        q.pop();
        
        if(time > d){
            return;
        }
        
        for(int i =0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx < 0 || yy <0 || xx >= m || yy >= n){
                continue;
            }
            
            if(abs(graph[yy][xx] - graph[y][x]) > t){
                continue;
            }
            
            if(graph[y][x] - graph[yy][xx] >= 0){
                if(dist[yy][xx] > time + 1){
                    dist[yy][xx] = time + 1;
                    q.push({{time + 1, graph[yy][xx]}, {xx, yy}});
                }
                else if(visited[yy][xx]){
                    continue;
                }
                else{
                    visited[yy][xx] = 1;
                    q.push({{time + 1, graph[yy][xx]}, {xx, yy}});
                }
            }else{
                if(dist[yy][xx] > time + pow(graph[yy][xx] - graph[y][x], 2)){
                    dist[yy][xx] = time + pow(graph[yy][xx] - graph[y][x], 2);
                    q.push({{time + pow(graph[yy][xx] - graph[y][x], 2), graph[yy][xx]}, {xx, yy}});
                }
                else if(visited[yy][xx]){
                    continue;
                }else{
                    visited[yy][xx] = 1;
                    q.push({{time + pow(graph[yy][xx] - graph[y][x], 2), graph[yy][xx]}, {xx, yy}});
                }
            }
            
        }
        
    }
    
}

void bfs2(){
    //time은 적을 수록  x, y;
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>>q;
    
    q.push({{0, -graph[0][0]}, {0, 0}});
    visited[0][0] = 1;
    re[0][0] = 0;
    
    while(!q.empty()){
        
        int time = q.top().first.first;
        
        int x = q.top().second.first;
        int y = q.top().second.second;
        
        q.pop();
        
        if(time > d){
            return;
        }
        
        for(int i =0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx < 0 || yy <0 || xx >= m || yy >= n){
                continue;
            }
            
            if(abs(graph[yy][xx] - graph[y][x]) > t){
                continue;
            }
            
            if(graph[y][x] - graph[yy][xx] <= 0){
                if(re[yy][xx] > time + 1){
                    re[yy][xx] = time + 1;
                    q.push({{time + 1, graph[yy][xx]}, {xx, yy}});
                }
                else if(visited[yy][xx]){
                    continue;
                }
                else{
                    visited[yy][xx] = 1;
                    q.push({{time + 1, graph[yy][xx]}, {xx, yy}});
                }
            }else{
                if(re[yy][xx] > time + pow(graph[yy][xx] - graph[y][x], 2)){
                    re[yy][xx] = time + pow(graph[yy][xx] - graph[y][x], 2);
                    q.push({{time + pow(graph[yy][xx] - graph[y][x], 2), graph[yy][xx]}, {xx, yy}});
                }
                else if(visited[yy][xx]){
                    continue;
                }else{
                    visited[yy][xx] = 1;
                    q.push({{time + pow(graph[yy][xx] - graph[y][x], 2), graph[yy][xx]}, {xx, yy}});
                }
            }
            
        }
        
    }
}


int main(){
    
    int max = 0;
    
    cin >> n >> m >> t >> d;
    
    for(int i =0; i< n; i++){
        for(int j = 0; j <m; j++){
            dist[i][j] = INF;
            re[i][j] = INF;
        }
    }
    
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            map[i][j] = c;
            graph[i][j] = change_int(map[i][j]);
        }
    }
    
    bfs();
    
    
    for(int i =0; i< 30; i++){
        for(int j = 0; j < 30; j++){
            visited[i][j] = 0;
        }
    }
    bfs2();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(max < graph[i][j] && dist[i][j] + re[i][j]<= d){
                max = graph[i][j];
            }
        }
    }
    
    cout << max;
    
}
