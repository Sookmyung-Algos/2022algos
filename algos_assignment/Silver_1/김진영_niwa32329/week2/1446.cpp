#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct info{
    int idx,val;
};
info tmp;
int dist[10001]; //0부터 각 노드까지의 길이를 미리 저장함 
vector<info> v[10001]; 
int main() {
    int num, goal,s,e,val,before;
    cin>>num>>goal; //지름길의 개수, 고속도로의 길이 입력 받기 
    for(int i=1;i<=goal;i++)
        dist[i]=i;
    for(int i=0;i<num;i++){
        cin>>s>>e>>val; //지름길의 시작 위치, 도착 위치, 지름길의 길이 
        if(e-s<=val) continue; //지름길이 아닌 경우 제외
        if(e>goal) continue;  //지름길의 도착지점이 목표지점을 넘어갈때 (역주행 불가능하므로) 제외 
        tmp.idx=e;
        tmp.val=val;
        v[s].push_back(tmp);
    }
    for(int i=0;i<=goal;i++){
        if(i==0) before = -1;
        else before = dist[i-1]; //이전 방문 노드 
        dist[i]=min(dist[i],before+1); //최소 방문거리를 택하여 dist[]에 갱신 
        if(!v[i].empty()){
            for(int k=0;k<v[i].size();k++){
                int to = v[i][k].idx; //노드 
                int cost = v[i][k].val; //비용 
                if(to>goal) continue;
                if(dist[i]+cost<dist[to]){ //최소거리 업데이트 
                    dist[to] = dist[i] + cost;
                }
            }
        }
    }
    cout<<dist[goal];
    return 0;
}
