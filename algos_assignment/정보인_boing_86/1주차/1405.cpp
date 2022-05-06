#include <iostream>
#include <algorithm>
using namespace std;

bool visited[30][30] = {false, };
double prob[4];
int prow[4] = { 1, -1, 0, 0 };
int pcol[4] = { 0, 0, 1, -1 };
int n;
double ans = 0.0;

double dfs(int x, int y, int d){

    if(d == n){
        return 1.0;
    }

    double ans_prob = 0.0;

    visited[x][y] = true;

    for(int i = 0; i<4; i++){
        int nx = x + prow[i];
        int ny = y + pcol[i];
        
        if(!visited[nx][ny]){
            ans_prob += prob[i] * dfs(nx, ny, d+1);
        }
    }
    visited[x][y] = false;
    return ans_prob;
}


int main(void){
    cin>>n;
    for(int i = 0; i<4; i++){
        int num;
        cin>>num;
        prob[i] = num/100.0;
    }

    ans = dfs(15, 15, 0);
    cout.precision(10);
    cout<<fixed<<ans<<endl;

    return 0;
}
