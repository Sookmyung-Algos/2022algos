#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int, int> >graph[101];
int d[101];
int v[101];
int n,r;

void dijkstra(int start)
{
    priority_queue<pair<int,int>>pq;
    
    pq.push({0,start});
    d[start]=0;
    v[start]=1;
    
    while(!pq.empty())
    {
        int dist = -pq.top().first; //요금
        int cur = pq.top().second;  //거점
        pq.pop();
        
        if(d[cur]<dist)
            continue;
        
        for(int i=0; i<graph[cur].size(); i++)
        {
            int cost = dist+graph[cur][i].first;
                    
            if(cost==d[graph[cur][i].second]){
                if(v[graph[cur][i].second]>v[cur]+1){
                    v[graph[cur][i].second]=v[cur]+1;
                    pq.push({-cost,graph[cur][i].second});
                }
            }
            if(cost<d[graph[cur][i].second])
            {
                d[graph[cur][i].second]=cost;
                v[graph[cur][i].second]=v[cur]+1;
                pq.push({-cost,graph[cur][i].second});
            }
        }
    }
}

int main(void)
{
    cin >> n >> r;
    
    for (int i = 0; i < r; i++)
    {
        int a, b, c,d,e;
        cin >> a >> b >> c >> d >> e;
        int fee = e>=10? c+(e-10)*d : c;
        
        graph[a].push_back({fee, b});
    }
        
    fill(d, d + 101, INF);
    fill(v, v+101, INF);
    dijkstra(1);
    
    if(d[n]==INF){
        cout<<"It is not a great way.";
    }
    else{
        cout<<d[n]<<' '<<v[n];
    }
}
