#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1000002
#define INF 9876543210

ll n, x, result;
ll seg[MAX];
ll h[MAX];

ll init(ll node, ll s, ll e){
    if (s == e)
        return seg[node] = s;
    
    ll mid = (s+e)/2;
    ll tempL = init(2*node, s, mid);
    ll tempR = init(2*node+1, mid+1, e);
    
    if (h[tempL] < h[tempR])
        return seg[node] = tempL;
    else
        return seg[node] = tempR;
}

ll query(ll node, ll s, ll e, ll l, ll r){
    if (e < l || r < s)
        return INF;
    
    if (l <= s && e <= r)
        return seg[node];
    
    ll mid = (s+e)/2;
    ll tempL = query(2*node, s, mid, l, r);
    ll tempR = query(2*node+1, mid+1, e, l, r);
    
    if (tempL == INF)
        return tempR;
    else if (tempR == INF)
        return tempL;
    else if (h[tempL] < h[tempR])
        return tempL;
    else
        return tempR;
}

void solve(ll l, ll r){
    if (l > r)
        return;
    
    ll temp = query(1, 0, n-1, l, r);
    result = max(result, h[temp] * (r-l+1));
    
    solve(l, temp-1);
    solve(temp+1, r);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    while (1){
        result = 0;
        cin>>n;
        if (n == 0)
            break;
        
        for (int i=0; i<n; i++)
            cin>>h[i];
        
        init(1, 0, n-1);
        solve(0, n-1);
        cout<<result<<"\n";
    }
}
