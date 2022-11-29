#include <iostream>

#define INF 987654321

using namespace std;
using pii = pair<int, int>;

vector<pii> vec[10001];
vector<int> dist(10001, INF);

int main(){
    int n, d; 
    
    cin >> n >> d;
    
    while (n--) {
        int s, e, w; 
       
        cin >> s >> e >> w;
      
        if (e > d) {
           continue;
        }
      
        vec[e].push_back({s, w});
    }
    
    dist[0] = 0;
    
    for (int i = 1; i <= d; i++){
        if (vec[i].size() == 0) {
           dist[i] = dist[i-1] + 1;
        }
      
        else {
            for (auto d: vec[i]) {
                dist[i] = min(dist[i], min(dist[i-1] + 1, dist[d.first] + d.second));
            }
        }
    }

    cout << dist[d] << "\n";
    
    return 0;
}
