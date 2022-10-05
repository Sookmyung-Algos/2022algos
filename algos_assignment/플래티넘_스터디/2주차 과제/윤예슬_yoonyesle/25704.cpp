#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p, ans;
    vector<int> comp;
    cin >> n >> p;
    ans = p;
    if (n >= 5)
        comp.push_back(p - 500);
    if (n >= 10)
        comp.push_back(p * 0.9);
    if (n >= 15)
        comp.push_back(p - 2000);
    if (n >= 20)
        comp.push_back(p * 0.75);
    for (int i: comp) {
        ans = min(ans, i);
    }
    cout << (ans > 0 ? ans : 0);
}
