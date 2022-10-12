#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string t,p;
    ll dp[1010101]={0,};
    
    getline(cin,t);
    getline(cin,p);
    
    ll k1=0;
    for (int i=1;i<p.size();i++){
        while (k1>0 && p[i]!=p[k1])
            k1=dp[k1-1];
        
        if (p[i]==p[k1]){
            k1++;
            dp[i]=k1;
        }
    }
    
    ll k2=0;
    vector <ll> result;
    for (int i=0;i<t.size();i++){
        while (k2>0 && t[i]!=p[k2])
            k2=dp[k2-1];
        
        if (t[i]==p[k2]){
            if (k2==p.size()-1){
                result.push_back(i-p.size()+2);
                k2=dp[k2];
            }
            else
                k2++;
        }
    }
    
    cout<<result.size()<<'\n';
    for (int i=0;i<result.size();i++)
        cout<<result[i]<<'\n';
}
