#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define NUM 200
using namespace std;
int n, k, d, c[2*NUM+10][2*NUM+10], f[2*NUM+10][2*NUM+10], s = 401, e = 402, answer = 0;
vector<int> graph[2*NUM+10];

void bfs() {
    while(true) {
        int prev[2*NUM+10];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1) {
            int now = q.front();
            q.pop();
            for(int i=0; i<graph[now].size(); i++) {
                int next = graph[now][i];
                if(c[now][next] - f[now][next] > 0 && prev[next] == -1) {
                    q.push(next);
                    prev[next] = now;
                    if(next == e) break;
                }
            }
        } 
        if(prev[e] == -1) break;
        int flow = 1e9;
        for(int i=e; i!=s; i=prev[i]) flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        for(int i=e; i!=s; i=prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        answer += flow;
    }
}


int main() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    cin >> n >> k >> d;
    for(int i=1; i<=d; i++) {
        int x;
        cin >> x;
        graph[i+NUM].push_back(e);
        graph[e].push_back(i+NUM);
        c[i+NUM][e] += x;
    }
    for(int i=1; i<=n; i++) {
        int x;
        graph[s].push_back(i);
        graph[i].push_back(s);
        c[s][i] += k;
        cin >> x;
        for(int j=1; j<=x; j++) {
            int y;
            cin >> y;
            graph[i].push_back(y+NUM);
            graph[y+NUM].push_back(i);
            c[i][y+NUM]++;
        }
    }
    bfs();
    cout << answer << '\n';
}
