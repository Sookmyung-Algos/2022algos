#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    int floyd[21][21];
    bool check[21][21]={false,};
    
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>floyd[i][j];
        }
    }

    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                
                if (i==j||i==k||j==k)
                    continue;
                
                if (floyd[i][j] > floyd[i][k]+floyd[k][j]){
                    cout<<"-1";
                    return 0;
                }
                
                if (floyd[i][j]==floyd[i][k]+floyd[k][j]){
                    check[i][j]=true;
                }
            }
        }
    }
    
    int result=0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (!check[i][j]){
                result+=floyd[i][j];
            }
        }
    }
    cout<<result;
}
