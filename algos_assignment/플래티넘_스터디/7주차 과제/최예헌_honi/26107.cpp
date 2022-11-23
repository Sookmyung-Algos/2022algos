#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 100002
#define INF 987654321

ll n, k;
ll group[MAX] = {0,};
ll sum[MAX] = {0,};
vector <tuple<ll, ll, ll>> v;   // start, end, num

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll a,b, c;
    
    cin>>n>>k;
    for (int i=1; i<=n; i++){
        cin>>a>>b;
        v.push_back({a, b, i});
    }
    sort(v.begin(), v.end());
    
    ll cnt = 1;
    ll s = get<0>(v[0]);
    ll e = get<1>(v[0]);
    group[get<2>(v[0])] = cnt;
    
    if (v.size() > 1){
        for (int i=1; i<v.size(); i++){
            // 같은 그룹
            ll nowidx = get<2>(v[i]);
            if (get<0>(v[i]) <= e){
                group[nowidx] = cnt;
                e = max(e, get<1>(v[i]));
            }
            
            // 다른 그룹
            else{
                sum[cnt] = sum[cnt-1] + (get<0>(v[i]) - e);
                cnt++;
                s = get<0>(v[i]);
                e = get<1>(v[i]);
                group[nowidx] = cnt;
            }
        }
    }
    
    ll temp = group[1];
    ll result = 0;
    for (int i=0; i<k; i++){
        cin>>c;
        if (temp == group[c])
            continue;
        
        else if (temp < group[c]){
            result += (sum[group[c]-1] - sum[temp-1]);
            temp = group[c];
        }
        
        else if (group[c] < temp){
            result += (sum[temp-1] - sum[group[c]-1]);
            temp = group[c];
        }
    }
    cout<<result;   
}
