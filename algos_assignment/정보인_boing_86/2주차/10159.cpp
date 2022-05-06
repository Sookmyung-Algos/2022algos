#include <iostream>
using namespace std;
int n,m;
int table[101][101] = {0, };

int main(){
    cin>>n>>m;

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        table[a][b] = 1;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(table[i][k] == 1 && table[k][j] == 1){
                    table[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i<=n; i++){
        int count = 0;
        for(int j = 1; j<=n; j++){
            if(table[i][j] == 0 && table[j][i] == 0){
                count++;
            }
        }

        cout<<count-1<<endl;
    }
    return 0;
}
