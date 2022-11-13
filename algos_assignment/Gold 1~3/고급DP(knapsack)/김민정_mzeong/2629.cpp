#include <bits/stdc++.h>
using namespace std;

int w[31], dp[31][15001], n;

void f(int i, int j){
    if(i > n || dp[i][j]) return;
    dp[i][j] = 1;
    f(i+1, j);
    f(i+1, j+w[i]);
    f(i+1, abs(j - w[i]));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    f(0, 0);
    int k; cin >> k;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        if(x > 15000) cout << "N\n";
        else cout << (dp[n][x] ? "Y\n" : "N\n");
    }
    return 0;
}
