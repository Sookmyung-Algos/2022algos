#include <iostream>
#include <algorithm>
#define MAX 12345;
using namespace std;

int n, m, r;
int t[101] = {0, };
int map[101][101] = {0, };

int main(){
    cin>>n>>m>>r;

    for(int i = 0; i<101; i++){
        for(int j = 0; j<101; j++){
            if(i!=j){
                map[i][j] = MAX;
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        cin>>t[i];
    }

    for(int i = 0; i<r; i++){
        int a, b, l;
        cin>>a>>b>>l;
        map[a][b] = l;
        map[b][a] = l;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<=n; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    int max_item = 0;
    for(int i = 1; i<=n; i++){
        int temp = 0;
        for(int j = 1; j<=n; j++){
            if(map[i][j]<= m){
                temp = temp + t[j];
            }
        }
        max_item = max(max_item, temp);

    }
    cout<<max_item;
}
