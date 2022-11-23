#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 10002
#define INF 987654321

int result = INF;
string str;

void solve(int s, int e, int cnt){
    if (s >= e){
        result = min(result, cnt);
        return;
    }
    
    if (str[s] == str[e])
        solve(s+1, e-1, cnt);
    
    else{
        if (cnt >= 3)
            return;
        
        else{
            solve(s+1, e, cnt+1);
            solve(s, e-1, cnt+1);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>str;
    solve(0, str.size()-1, 0);
    
    if (result == INF)
        cout<<"-1";
    else
        cout<<result;
}
