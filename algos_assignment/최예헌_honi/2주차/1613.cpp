#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define MAX 9876543210

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m,s;
    int a,b;
    ll floyd[401][401];
    
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j)
                floyd[i][j]=0;
            else
                floyd[i][j]=MAX;
        }
    }
    
    for (int i=0;i<m;i++){
        cin>>a>>b;
        floyd[a][b]=1;
    }
    
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j || floyd[i][j]==1)
                    continue;
                
                else{
                    if (floyd[i][k]!=MAX && floyd[k][j]!=MAX){
                        floyd[i][j]=1;
                    }
                }
            }
        }
    }
    
    cin>>s;
    for (int i=0;i<s;i++){
        cin>>a>>b;
        if (floyd[a][b]==1)
            cout<<"-1\n";
        else if (floyd[b][a]==1)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    
}
