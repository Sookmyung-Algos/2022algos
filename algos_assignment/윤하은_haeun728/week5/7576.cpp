#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int M,N, cnt=0, result=0;
int xDir[4]={0,0,-1,1}, yDir[4]={1,-1,0,0};
queue<pair<int,int>> q;

int main() {
    cin >> M >> N;
    int box[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>box[i][j];
            if(box[i][j]==1) q.push(make_pair(i,j));
            
            else if(box[i][j]==0) cnt++;
        }
    }
    
    while(!q.empty()){
        pair<int, int> e;
        e = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int xPos = e.second+xDir[i], yPos=e.first+yDir[i];
            if(xPos < 0 || xPos > M-1 || yPos <0 || yPos > N-1) continue;
            if(box[yPos][xPos]==0){
                box[yPos][xPos]=box[e.first][e.second]+1;
                q.push(make_pair(yPos,xPos));
                cnt--;
            }
            
        }
    }

    for(int k=0;k<N;k++)
        for(int z=0;z<M;z++)
            if(box[k][z] > result) result = box[k][z];
            
    if(cnt != 0) result = -1;
    else result-=1;
    cout<<result;

}
