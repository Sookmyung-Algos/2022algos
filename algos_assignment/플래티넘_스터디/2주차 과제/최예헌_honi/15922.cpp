#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, x, y;    // n번의 횟수, 두 점
    vector<pair<ll,ll>> v;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    
    ll result = 0;
    ll l = -9876543210;
    ll r = -9876543210;
    
    for (int i=0;i<n;i++){
        if (v[i].first > r){
            result += (r-l);
            l = v[i].first;
            r = v[i].second;
        }
        else
            r = max(r, v[i].second);
    }
    result += (r-l);
    cout<<result;
}
