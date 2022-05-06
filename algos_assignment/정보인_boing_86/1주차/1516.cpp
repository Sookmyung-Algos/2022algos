#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int inDegree[501];
vector <int> v[501];
int btime[501];
int result[501] = {0, };

void topology_Sort(){

    queue <int> q;

    for(int i = 1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(i);
            result[i] = btime[i];
        }
    }

    for(int i = 1; i<=n; i++){

        if(q.empty()){
            //cycle 이 있음.
            break;
        }

        int x = q.front();
        q.pop();
        
        for(int i  = 0; i<v[x].size(); i++){
            int y = v[x][i];
            result[y] = max(result[y], result[x] + btime[y]);

            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }
}
int main(){
    cin>>n;

    for(int i = 1; i<=n; i++){
        cin>>btime[i];

        while(true){
            int a;
            cin>>a;
            if(a == -1){
                break;
            }
            v[a].push_back(i);
            inDegree[i]++;
        }
    }

    topology_Sort();

    for(int i  = 1; i<=n; i++){
        cout<<result[i]<<endl;
    }
}
