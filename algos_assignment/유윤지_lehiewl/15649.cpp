#include <iostream>
#include<vector>
using namespace std;
#define MAX 9

int n, m;
bool check[9];
vector<int> v;

void find(int index) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(i);
        find(index + 1);
        v.pop_back();
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    find(0);
}
