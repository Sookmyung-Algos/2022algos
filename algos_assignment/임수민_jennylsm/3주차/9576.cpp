#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> pq;
bool book[1001];


int main (void){
    int tc;
    int n, m;
    int a, b;
    int cnt= 0;
    
    scanf("%d", &tc);
    for(int i=0; i<tc; i++){
        cnt = 0;
        scanf("%d %d", &n, &m);
        for(int j=1; j<=n; j++){
            book[j] = false;
        }
        for(int j=0; j<m; j++){
            scanf("%d %d", &a, &b);
            pq.push( make_pair(-b, -a));
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
        printf("%d\n", cnt);
        
    }
    
}
