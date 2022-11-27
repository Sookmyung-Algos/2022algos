#include <iostream>
#include <vector>

using namespace std;

const int INF = 10005;
int n, d, from, to, dis;

vector<int> m(10005, INF);
vector<pair<int, int>> v[10005];

int main(){
    ios_base::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++){
        cin >> from >> to >> dis;
      
        if(to > d || to - from < dis)
          continue;
      
        v[to].push_back({from, dis});
    }
  
    m[0] = 0;

    for(int i = 1; i <= d; i++){
        m[i] = m[i-1] +1;
      
        for(int j=0; j<(int) v[i].size(); j++){
                m[i] = min(m[i], m[v[i][j].first]+v[i][j].second);
        }
    }
    cout << m[d] << "\n";
}

//참고 출처: https://velog.io/@minayeah/C-%EB%B0%B1%EC%A4%80-1446-%EC%A7%80%EB%A6%84%EA%B8%B8
