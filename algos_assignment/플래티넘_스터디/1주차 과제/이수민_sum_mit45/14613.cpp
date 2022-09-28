#include <iostream>
#define ll long long
#define ld long double
using namespace std;

ld W,L,D;
ld dp[41][21];
ld ans[5];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> W >> L >> D;
    
    dp[20][0]=1;
    for(int i=0; i<20; i++){
        for(int j=0; j<41; j++){
            if(dp[j][i]!=0){ //값이 있으면
                //cout <<  i << " " << j << " ";
                cout << fixed; cout.precision(15);
                //cout << dp[j][i] << "\n";
                dp[j-1][i+1]+=dp[j][i]*L;
                dp[j+1][i+1]+=dp[j][i]*W;
                dp[j][i+1]+=dp[j][i]*D;
//                if(dp[j-1][i+1] > 1 || dp[j-1][i+1] <0){
//                    cout << "overflow\n";
//                }
//                else if(dp[j+1][i+1] >1  || dp[j+1][i+1]<0){
//                    cout << "overflow\n";
//                }
            }
        }
       
    }
    
    //cout << "ss" << dp[19][40] << "\n";
    ld bronze, silver, gold, platinum, dia;
    for(int i=0; i<41; i++){
        // cout << i << " " << dp[i][20] << "\n";
        if(i<10) ans[0] += dp[i][20];
        else if(i<20) ans[1] += dp[i][20];
        else if(i<30) ans[2] += dp[i][20];
        else if(i<40) ans[3] += dp[i][20];
        else ans[4] += dp[i][20];
    }
    //cout << fixed; cout.precision(15);
    cout << fixed; cout.precision(8);
    for(int i=0; i<5; i++) cout << ans[i] <<"\n";
    return 0;
}
