#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

int N,S,D;
vector<int> v[MAX];
int arr[MAX];

int ans =0;

int dfs(int cur, int p) {
    int mmax=0;
    for(auto next: v[cur]){
        if(next != p){
            mmax = max(mmax, dfs(next,cur)+1);
        }
    }
    arr[cur] = mmax;
    return arr[cur];
}

void search(int cur, int p){
    for (auto next : v[cur]){
        if(next!=p){
            if(arr[next] >= D){
                ans++;
                search(next, cur);
                ans++;
            }
        }
    }
    return;
}


int main(){
    cin>>N>>S>>D;
    
    for(int i=1; i<N; i++){
        int x,y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    dfs(S,0);
    search(S,0);
    
    cout << ans;
    
    return 0;
}
