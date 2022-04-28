#include <iostream>
#include <cmath>
using namespace std;
int N,L,R,ans=0,sum,cnt,pos=1;
int map[51][51],tmap[51][51],visited[51][51],zero[51][51];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
 
void map_copy(int (*a)[51],int (*b)[51]){
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        a[i][j]=b[i][j];
}
 
void dfs(int x,int y){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0||ny<0||nx>N-1||ny>N-1)continue;
            if(abs(map[x][y]-map[nx][ny])>=L&&abs(map[x][y]-map[nx][ny])<=R&&!visited[nx][ny]){
            visited[nx][ny]=pos;dfs(nx,ny);}
        }    
    
}
 
void move(){
    sum=0;cnt=0;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(visited[i][j]==pos){sum+=map[i][j];cnt++;}
    
    sum/=cnt;
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(visited[i][j]==pos)tmap[i][j]=sum;
        
    pos++;
}
 
void make_union(){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx<0||ny<0||nx>N-1||ny>N-1)continue;
                    if(abs(map[x][y]-map[nx][ny])>=L&&abs(map[x][y]-map[nx][ny])<=R&&!visited[x][y]){
                    visited[x][y]=pos;
                    dfs(x,y);
                    move();
                    }
                }
        }
    }
}
 
bool end(){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx<0||ny<0||nx>N-1||ny>N-1)continue;
                    if(abs(map[x][y]-map[nx][ny])>=L&&abs(map[x][y]-map[nx][ny])<=R){
                    return true;
                    }
                }        
        }
    }
    return false;
}
 
void solve(){
    map_copy(tmap,map);
    while(end()){
    map_copy(visited,zero);
    make_union();
    map_copy(map,tmap);
    pos=1;ans++;
    }
    cout<<ans;
}
 
main(){
    ios::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
    cin>>N>>L>>R;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
    
    solve();
}
