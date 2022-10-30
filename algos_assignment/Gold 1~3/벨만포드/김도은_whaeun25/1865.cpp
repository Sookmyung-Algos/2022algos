#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define MAX 510

using namespace std;

int main(){
    
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        
        int n, m, w;
        
        cin >> n >> m >> w;
        
        vector<long long> dist(n + 1, MAX);
        vector <pair<pair<int, int>, int>> edge;
        
        // 입력
        for(int i = 0; i < m; i++){
            // t는 이 도로를 통해 이동하는데 걸리는 시간
            int s, e, t;
            
            cin >> s >> e >> t;
            //도로가 무방향이므로 양방향으로 간선 추가
            edge.push_back({{s, e}, t});
            edge.push_back({{e, s}, t});
        }
        
        for(int i = 0; i < w; i++){
            //t는 줄어드는 시간
            int s, e, t;
            
            cin >> s >> e >> t;
            
            //웜홀의 가중치
            edge.push_back({{s, e}, -t});
        }
        
        dist[1] = 0;
        
        // 모든 정점으로 도달할 수 있는 최소 시간
        for(int i = 1; i < n; i++){
            for(int j = 0; j < edge.size(); j++){
                int s = edge[j].first.first;
                int e = edge[j].first.second;
                
                int t = edge[j].second;
                
                // 더 적은 시간으로 도달할 수 있으면 갱신
                if(dist[e] > dist[s] + t){
                    dist[e] = dist[s] + t;
                }
                
            }
        }
        
        int check = 0;
        
        for(int i = 0; i < edge.size(); i++){
            int s = edge[i].first.first;
            int e = edge[i].first.second;
            
            int t = edge[i].second;
            
            // 시간이 되돌아가 있는 경우
            if(dist[e] > dist[s] + t){
                cout << "YES\n";
                
                check = 1;
                break;
            }
        }
        
        // 시간이 되돌아가는 경우가 없는 경우
        if(check == 0){
            cout << "NO\n";
        }
        
    }
}
