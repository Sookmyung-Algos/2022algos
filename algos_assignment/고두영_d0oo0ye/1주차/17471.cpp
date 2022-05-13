#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, result = 9999999;
int cost[11];
bool visit[11], visited1[11], visited2[11];

vector<int> graph[11];
vector<int> checkli;

void find() {
    vector<int> compare;
    int a = 0, b = 0;

    fill(visited1, visited1 + 11, false);
    fill(visited2, visited2 + 11, false);

    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            compare.push_back(i);
            visited2[i] = true;
        }
        else {
            visited1[i] = true;
        }
    }

    queue<int> q;
    q.push(checkli[0]);
    visited1[checkli[0]] = false;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            for (int j = 0; j < checkli.size(); j++) {
                if (graph[now][i] == checkli[j] && visited1[checkli[j]] == true) {
                    visited1[checkli[j]] = false;
                    q.push(checkli[j]);
                }
            }
        }
    }
    for (int i = 0; i < checkli.size(); i++) {
        a += cost[checkli[i]];

        if (visited1[checkli[i]]) {
            return;
        }
    }

    q.push(compare[0]);
    visited2[compare[0]] = false;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            for (int j = 0; j < compare.size(); j++) {
                if (graph[now][i] == compare[j] && visited2[compare[j]] == true) {
                    visited2[compare[j]] = false;
                    q.push(compare[j]);
                }
            }
        }
    }

    for (int i = 0; i < compare.size(); i++) {
        b += cost[compare[i]];

        if (visited2[compare[i]]) {
            return;
        }
    }
    result = min(abs(a - b), result);
}


void select(int cnt) {
    if (cnt > n / 2) return;
    if (cnt != 0) {
        find();
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;

        checkli.push_back(i);
        visit[i] = true;
        select(cnt + 1);

        checkli.pop_back();
        visit[i] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            graph[i].push_back(b);
        }
    }
    select(0);
    if (result == 9999999) result = -1;
    cout << result << endl;
}
