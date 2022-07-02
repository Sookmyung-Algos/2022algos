#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void dfs(int n, int now, int B);

int family[101][101];
int visit[100];
int cnt = -1;
int sol = -1;

int main(void){
    int n, m;
    int A, B;
    int p, c;

    scanf("%d", &n);
    scanf("%d %d", &A, &B);
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &p, &c);
        family[p][c] = 1;
        family[c][p] = 1;
    }
    
    dfs(n, A, B);
    
    printf("%d\n", sol);
}

void dfs(int v) 
{
    cout << v << ' ' ;
    visit[v] = 1;
    for(int i=1; i<=N; i++) 
    {
        if(visit[i] == 1 || adj[v][i] == 0)
            continue;
        dfs(i); 
    }
}
