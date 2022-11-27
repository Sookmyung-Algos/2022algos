#include <iostream>
#include <vector>
using namespace std;


const int INF = 10005;
int N,D;

int from, to, cost;

vector<int> m(10005, INF);
vector<pair<int, int>> v[10005];

int main(){

    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);

    cin>>N>>D;

    for(int i=0; i<N; i++){
        cin>>from>>to>>cost;
        if(to>D || to-from<cost) continue;
        v[to].push_back({from, cost});
    }


    m[0]=0;

    for(int i=1; i<=D; i++){
        m[i]= m[i-1] +1;
        for(int j=0; j<(int) v[i].size(); j++){
                m[i] = min(m[i], m[v[i][j].first]+v[i][j].second);
            }
        
    }



    cout<<m[D];
}
