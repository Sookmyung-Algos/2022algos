#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    map<int, multiset<int>> coord;
    int N; cin >> N;
    int x, y;

    for (; N--;) {
        cin >> x >> y;
        coord[x].insert(y);
    }

    for (auto& i : coord) {
        for (auto& j : i.second) {
            cout << i.first << ' ' << j << '\n';
        }
    }
    
    return 0;
}
