#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct Vertex{
  int r;
  int c;
  int time;
};

const int INF = 987654321;
int height, width, grave_num, hole_num;
bool is_grave[31][31], is_hole[31][31];
int change_pos[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<vector<vector<Vertex>>> adj;
vector<vector<int>> upper;

bool BellmanFord(){
  bool is_updated = false;

  int time, next_r ,next_c;
  for(int iter =0; iter<=height*width-grave_num ; ++iter){
    for(int r =0; r<height ; ++r){
      for(int c = 0; c<width ; ++c){
        if(is_grave[r][c]) continue;
        if(upper[r][c] == INF)  
          continue; //다른 컴포넌트에 음의 사이클이 있을 수 있으므로 INF인 점에서는 완화 시도 x

        for(int i=0; i<adj[r][c].size() ; ++i){
          next_r = adj[r][c][i].r;
          next_c = adj[r][c][i].c;
          time = adj[r][c][i].time;

          if(time + upper[r][c] < upper[next_r][next_c]){
            if(iter == height*width-grave_num)
              is_updated = true;
            upper[next_r][next_c] = time + upper[r][c];
          }
        }

      }
    }
  }

  if(is_updated)  //음의 사이클이 있는 경우
    return true;
  return false;
}

void GraphCreate(){
  int next_r ,next_c, out_r, out_c,time;

  for(int r =0 ; r<height ; ++r){
    for(int c=0; c<width ; ++c){
      if(is_grave[r][c] || is_hole[r][c])
        continue;
      if(r==(height-1) && c == (width -1))
        continue; //탈출 정점에서는 다른 곳으로 간선을 이어서는 안됨

      for(int i=0; i<4 ; ++i){
        next_r = r + change_pos[i][0];
        next_c = c + change_pos[i][1];
        if(next_r<0 || height<= next_r || next_c<0 || width<=next_c)
          continue; //범위 초과시

        if(is_grave[next_r][next_c])
          continue;
        adj[r][c].push_back({next_r, next_c,1});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);

  while(1){
    cin>>width>>height;
    if(width == 0)
      break;

    cin>>grave_num;
    adj = vector<vector<vector<Vertex>>>(height, vector<vector<Vertex>>(width));
    memset(is_grave, false, sizeof(is_grave));
    memset(is_hole, false, sizeof(is_hole));

    int r,c;
    for(int i=0; i<grave_num ; ++i){
      cin>>c>>r;
      is_grave[r][c] = true;
    }

    int in_r, in_c, out_r, out_c, time;
    cin>>hole_num;
    for(int i=0; i<hole_num ; ++i){
      cin>>in_c>>in_r>>out_c>>out_r>>time;
      is_hole[in_r][in_c] = true;
      adj[in_r][in_c].push_back({out_r,out_c,time});  // 귀신 구멍의 탈출구로 간선을 이어주자.
    }

    GraphCreate();
    
    upper = vector<vector<int>>(height, vector<int>(width, INF));
    upper[0][0] = 0;

    bool is_cycle = BellmanFord();
    if(is_cycle)
      cout<<"Never\n";
    else if(upper[height-1][width-1] ==INF)
      cout<<"Impossible\n";
    else
      cout<<upper[height-1][width-1]<<"\n";
  
  }
  return 0;
}
