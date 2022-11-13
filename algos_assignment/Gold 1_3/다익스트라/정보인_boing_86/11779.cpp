#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 87654321;
vector<pair<int, int>> arr[1001];
priority_queue<pair<int, int>> pq;
int result[1001];
int layover[1001];

void dijkstra(int from, int to){
    pq.push({0, from});

    while(!pq.empty()){
        int dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(result[current] < dist) continue;

        for(int i = 0; i<arr[current].size(); i++){
            int n_dist = arr[current][i].first + dist;
            int next = arr[current][i].second;
            
            if(n_dist < result[next]){
                result[next] = n_dist;
                layover[next] = current;
                pq.push({-n_dist, next});
            }
        }
    }
}

int main(){
    int n, m;

    cin>>n>>m;

    for(int i = 0; i<=n; i++){
        result[i] = INF;
    }

    for(int i = 0; i<m; i++){
        int start, dest, cost;
        cin>>start>>dest>>cost;
        arr[start].push_back({cost, dest});
    }
    int from, to;
    cin>>from>>to;

    result[from] = 0;
    dijkstra(from, to);

    cout<<result[to]<<"\n";

    vector<int> path;

    int node = to;
    while(node){
        path.push_back(node);
        node = layover[node];
    }

    cout<<path.size()<<endl;

    for(int i = path.size()-1; i>=0; i--){
        cout<<path[i]<<" ";
    }

    return 0;
}
