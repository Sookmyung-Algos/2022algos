#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define MAX 987654321

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, m, x;
    vector <int> v;
    int cnt=0, result=0;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
        if (x<0)
            cnt++;
    }
    
    sort(v.begin(), v.end());
    
    int temp=0;
    while (temp<cnt){
        result += abs(v[temp])*2;
        temp+=m;
    }
    
    for (int i=n-1; i>=cnt; i-=m){
        result += v[i]*2;
    }
    
    cout<<result-max(abs(v[0]),v[n-1]);   
}
