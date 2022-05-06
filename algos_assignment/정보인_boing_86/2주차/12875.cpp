#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
const int MAX = 50;
int map[51][51] = {0, };

int main(){
    cin>>n;
    cin>>d;

    for(int i = 0; i<51; i++){
        for(int j = 0; j<51; j++){
            if(i!=j){
                map[i][j] = MAX;
            }
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            char c;
            cin>>c;
            if(c == 'Y'){
                map[i][j] = 1;
            }
        }
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    int max_edge = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            max_edge = max(max_edge, map[i][j]);
        }
    }

    if(max_edge == MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<max_edge*d<<endl;
    }
}
