#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
bool book[1001];
int tc, n, m, a, b, cnt = 0;

int main (void){
    cin >> tc;
    for(int i=0; i<tc; i++){
        cnt = 0;
        cin >> n >> m;
        for(int j=1; j<=n; j++) book[j] = false;
        for(int j=0; j<m; j++){
            cin >> a >> b;
            pq.push({-b, -a});
        }
                    
        while(!pq.empty()){
            b = -pq.top().first;
            a = -pq.top().second;
            pq.pop();
            
            for(int i=a; i<=b; i++){
                if(book[i]==false){
                    book[i] = true;
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }
}
