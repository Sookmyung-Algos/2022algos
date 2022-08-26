#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 100001
using namespace std;

struct wood
{
    int num, x1, x2;
    wood() {}
    wood(int a, int b, int c) :num(a), x1(b), x2(c) {}
};
bool compare(wood a, wood b) {
    return a.x1 < b.x1;
}
int N, Q;
int parent[MAX];
wood woods[MAX];

void unionParent() {
    int p = 0, right = woods[0].x2;
    parent[0] = 0;

    for (int i = 1; i < N; i++) {
        if (woods[i].x1 <= right) {
            right = max(right, woods[i].x2);
        }
        else {
            p++;
            right = woods[i].x2;
        }
        parent[woods[i].num] = p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, x1, x2, y;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> x1 >> x2 >> y;
        woods[i] = wood(i, x1, x2);
    }
    sort(woods, woods+N, compare);
    unionParent();
    while (Q--) {
        cin >> a >> b;
        a--, b--;
        if (parent[a] == parent[b]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
