#include <iostream>

using namespace std;

int n, m;
int map[101][101];

int min(int a, int b){
    return a < b ? a : b;
}

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                else if (map[i][k] && map[k][j]){
                    if(map[i][j] == 0) map[i][j] = map[i][k] + map[k][j]; // 1번 경우
                    else map[i][j] = min(map[i][j], map[i][k]+map[k][j]); // 2번 경우
                }
            }
        }
    }
}

int main(void){
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int node1, node2;
        cin >> node1 >> node2;
        map[node1][node2] = 1;
        map[node2][node1] = 1;
    }
    
    floyd();
    
    int result = 987654321;
    int person;
    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=n; j++) sum+= map[i][j];
        if(result > sum){
            result = sum;
            person = i;
        }
    }
    
    cout << person << endl;
    
    return 0;
}
