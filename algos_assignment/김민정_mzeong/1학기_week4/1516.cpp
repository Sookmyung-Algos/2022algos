#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buildtime[501], cnt[501], ans[501];
vector<int> v[501];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> buildtime[i];
        while (1) {
            int num; cin >> num;
            if (num == -1) break;
            v[num].push_back(i);
            cnt[i]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) q.push(i);
        ans[i] = buildtime[i];
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int next : v[cur]) {
            cnt[next]--;
            
            ans[next] = max(ans[next], ans[cur] + buildtime[next]);
            if (cnt[next] == 0) q.push(next);
        }
    }
    
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}
