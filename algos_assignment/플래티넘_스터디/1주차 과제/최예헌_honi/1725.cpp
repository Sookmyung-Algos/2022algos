#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll n;
ll arr[100002];
stack<ll> s;
ll result = 0;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    s.push(0);
    for (int i=1;i<=n+1;i++){
        while (true){
            ll temp = s.top();
            if (s.empty() || arr[temp] <= arr[i])
                break;
            
            s.pop();
            result = max(result, arr[temp]*(i-s.top()-1));
        }
        s.push(i);
    }
    cout<<result;
}
