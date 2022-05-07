#include<iostream>

using namespace std;
long long n,m,N[100001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> N[i];
    }
    
    long long ans = 0, tmp = 0;
    for(int i = 1; i <= m; i++){
        tmp += N[i];
    }
    
    ans=tmp;
    for(int i = m + 1; i <= n; i++){
        tmp = tmp + N[i] - N[i-m];
        ans = max(ans, tmp);
    }
    cout << ans ;
}
