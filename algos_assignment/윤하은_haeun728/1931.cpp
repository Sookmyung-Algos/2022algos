#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int savetime = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (savetime <= a[i].second) {
            savetime = a[i].first;
            ans++;
        }
    }
    printf("%d\n", ans);

}
