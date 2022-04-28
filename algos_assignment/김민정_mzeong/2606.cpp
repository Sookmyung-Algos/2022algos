#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> network[101];
bool visit[101];
int infect;

void bfs(int c1){
    queue<int> q;
    visit[c1] = true;
    q.push(c1);
    while(!q.empty()){
        int com = q.front(); q.pop();
        for (int i = 0; i < network[com].size(); i++){
            int next = network[com][i];
            if (!visit[next]){
                visit[next] = true;
                q.push(next);
                infect++;
            }
        }
    }
}

int main()
{
    int c; cin >> c;
    int p; cin >> p;
    for (int i = 0; i < p; i++){
        int c1, c2; cin >> c1 >> c2;
        network[c1].push_back(c2);
        network[c2].push_back(c1);
    }
    bfs(1);
    cout << infect;
    return 0;
}
