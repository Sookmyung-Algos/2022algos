#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#define MAX 11
using namespace std;

int n;  // n: 구역 개수
int popul[MAX];
int ans = INT_MAX;
vector<int> edge[MAX];  // 간선 정보, 2차원 벡터
bool selected[MAX];
bool visited[MAX];

bool isAllConnected(vector<int> v, bool sel) {  // 선택된 선거구가 연결되었는지, bfs로 확인
    memset(visited, false, sizeof(visited));
    queue<int> q;

    visited[v.front()] = true;  // ?
    q.push(v.front());
    int cnt = 1;  // 선거구역 개수 기억

    while (!q.empty()) {
        int next = q.front();
        q.pop();

        for (int i = 0; i < edge[next].size(); i++) {  // next와 연결된 구역 탐색
            int val = edge[next][i];
            if (selected[val] != sel || visited[val])  // 선거구역 정보가 맞지 않거나 이미 방문한 구역이면
                continue;
            cnt++;
            visited[val] = true;
            q.push(val);
        }
    }
    if (v.size() == cnt)  // 탐색한 구역 개수와 받아온 구역 개수가 같다면 모두 연결된 상태
        return true;
    else
        return false;
}

bool isAbleToDivide() {  // 선거구가 될 조건에 만족하는지
    vector<int> a;  // 선택된
    vector<int> b;  // 선택되지 않은

    for (int i = 1; i <= n; i++) {  // 나뉜 구역 벡터에 push
        if (selected[i]) a.push_back(i);
        else b.push_back(i);
    }

    if (a.empty() || b.empty())  // 비어있다면 false
        return false;
    if (!isAllConnected(a, true))
        return false;
    if (!isAllConnected(b, false))  // 연결여부확인
        return false;

    return true;
}

void calcPopul() {
    int aSum = 0;
    int bSum = 0;
    for (int i = 1; i <= n; i++) {
        if (selected[i]) aSum += popul[i];
        else bSum += popul[i];
    }
    ans = min(ans, abs(aSum - bSum));  // 더 작은 값으로 ans 갱신
}

// 1을 포함하는 조합, 1포함X+2포함하는 조합 ....
void dfs(int start, int cnt) {  // 선거구의 조합 구하기
    if (cnt >= 1) {
        if (isAbleToDivide())
            calcPopul();
    }
    for (int i = start; i <= n; i++) {
        if (selected[i])
            continue;
        selected[i] = true;  // i번째 구역 선택
        dfs(start + 1, cnt + 1);
        selected[i] = false;  // i번째 구역 선택 초기화, 다음 반복
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> popul[i];
    }

    int m, k;  // 입력 위한 임시 변수
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            edge[i].push_back(k);
        }
    }
    dfs(1, 0);

    if (ans == INT_MAX)
        cout << "-1";
    else
        cout << ans;
    return 0;
}
