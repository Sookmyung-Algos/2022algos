#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tll;
#define MAX 1002
#define INF 987654321

ll n, m, x, y;
vector <tll> v;     // x, y, type
ll Px;
ll Ly, Uy;
bool flag = false;
ll result = 0;
ll cnt = 0;

void solve(){
    ll sum = 0;
    for (int i=0; i<v.size(); i++){
        ll nowx = get<0>(v[i]);
        ll nowy = get<1>(v[i]);
        ll nowt = get<2>(v[i]);
        
        // L
        if (nowt == 1){
            if (Ly > Uy){
                if (nowy < Uy){
                    Px = nowx;
                    flag = true;
                }
            }
            
            else if (Uy > Ly){
                if (flag){
                    sum += (nowx - Px)*(Uy - Ly);
                    Px = nowx;
                    
                    if (nowy > Uy){
                        flag = false;
                        result += sum;
                        sum = 0;
                        cnt++;
                    }
                }
                
            }
            Ly = nowy;
        }
        
        // U
        else if (nowt == 2){
            if (Ly > Uy){
                if (nowy > Ly){
                    Px = nowx;
                    flag = true;
                }
            }
            else if (Uy > Ly){
                if (flag){
                    sum += (nowx - Px)*(Uy - Ly);
                    Px = nowx;
                    
                    if (nowy < Ly){
                        flag = false;
                        result += sum;
                        sum = 0;
                        cnt++;
                    }
                }
            }
            Uy = nowy;
        }
        
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    // L
    cin>>y;
    Ly = y;
    for (int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x, y, 1});
    }
    
    // U
    cin>>y;
    Uy = y;
    for (int i=0; i<m; i++){
        cin>>x>>y;
        v.push_back({x, y, 2});
    }
    
    sort(v.begin(), v.end());
    solve();
    cout<<cnt<<" "<<result;
}
