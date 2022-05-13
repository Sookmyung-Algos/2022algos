#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 987654321

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n;
    ll arr[6];
    ll sum=0, maxarr=0;
    ll min1=MAX, min2=MAX, min3=MAX;
    
    cin>>n;
    for (int i=0;i<6;i++){
        cin>>arr[i];
        sum+=arr[i];
        maxarr = max(maxarr, arr[i]);
    }
    
    if (n==1){
        cout<<sum-maxarr;
        return 0;
    }
    
    for (int i=0;i<6;i++){
        min1 = min(min1, arr[i]);
        
        for (int j=i+1;j<6;j++){
            if (i+j == 5)
                continue;
            min2 = min(min2, arr[i]+arr[j]);
            
            for (int k=j+1;k<6;k++){
                if (i+k == 5 || j+k == 5)
                    continue;
                min3 = min(min3, arr[i]+arr[j]+arr[k]);
            }
        }
    }
    
    cout<< 4*min3 + (8*n-12)*min2 + (5*n*n-16*n+12)*min1;
}
