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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    int a,b,c;
    ll floyd[101][101];
    
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
        cin>>a>>b>>c;
        if (floyd[a][b]>c)
            floyd[a][b]=c;
    }
    
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j)
                    continue;
                
                else{
                    if (floyd[i][j] > floyd[i][k]+floyd[k][j]){
                        floyd[i][j]=floyd[i][k]+floyd[k][j];
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j || floyd[i][j]>=MAX)
                cout<<"0 ";
            else
                cout<<floyd[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}
