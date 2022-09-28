#include <iostream>
#define ll long long
#define ld long double
using namespace std;

int N;
ld parr[100010];
ld ans=0;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> parr[i];
        ans += parr[i];
    }
    
    for(int i=1; i<N; i++){ //사이의 전구가 켜질 확률
        ans += (parr[i-1]*(1-parr[i]) + (1-parr[i-1])*parr[i]);
    }
    cout << fixed; cout.precision(6);
    cout << ans;
    
    return 0;
}
