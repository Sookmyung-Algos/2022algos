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

    int n,m;
    int a,b;
    ll floyd1[501][501];
    ll floyd2[501][501];
   
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j){
                floyd1[i][j]=0;
                floyd2[i][j]=0;
            }
            else{
                floyd1[i][j]=MAX;
                floyd2[i][j]=MAX;
            }
        }
    }
    
    for (int i=0;i<m;i++){
        cin>>a>>b;
        floyd1[a][b]=1;
        floyd2[b][a]=1;
    }
    
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j)
                    continue;
                
                else{
                    if (floyd1[i][j]>floyd1[i][k]+floyd1[k][j]){
                        floyd1[i][j]=floyd1[i][k]+floyd1[k][j];
                    }
                    if (floyd2[i][j]>floyd2[i][k]+floyd2[k][j]){
                        floyd2[i][j]=floyd2[i][k]+floyd2[k][j];
                    }
                }
            }
        }
    }
    
    int result=0;
    for (int i=1;i<=n;i++){
        int cnt=0;

        for (int j=1;j<=n;j++){
            if (i==j)
                continue;
            
            if ((floyd1[i][j]>0&&floyd1[i][j]<MAX) ||(floyd2[i][j]>0&&floyd2[i][j]<MAX)){
                cnt++;
            }
        }
        if (cnt==n-1){
            result++;
        }
    }
    cout<<result;
}
