#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

void fast_io(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    fast_io();
    list<int> lis;

    int k, m;
    cin >> k >> m;

    for (int i = 0; i < k; i++) {
        lis.push_back(i + 1);
    }

    std::list<int>::iterator it;

    while (m--) {
        int r, i = 1;
        cin >> r;

        it = lis.begin();
        while (it != lis.end()) {
            if (i % r == 0) {
                it = lis.erase(it++);
            }
            else
                it++;
            i++;
        }
    }
    for (auto it = lis.begin(); it != lis.end(); it++) {
        cout << *it << "\n";
    }
}
