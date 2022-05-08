#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char>w1;
    stack<char>w2;
    string w;
    int n;
    char a, b;
    cin >> w;
    for (int i = 0; i < w.size(); i++) {
        w1.push_back(w[i]);
    }
    cin >> n;
    while (n--) {
        cin >> a;
        if (a == 'L') {
            if (w1.size() == 0)continue;
            w2.push(w1.back());
            w1.pop_back();
        }
        else if (a == 'D') {
            if (w2.size() == 0)continue;
            w1.push_back(w2.top());
            w2.pop();
        }
        else if (a == 'B') {
            if (w1.size() == 0)continue;
            w1.pop_back();
        }
        else if (a == 'P') {
            cin >> b;
            w1.push_back(b);
        }
    }
    for (int i = 0; i < w1.size(); i++) {
        cout << w1[i];
    }
    while (w2.size()) {
        cout << w2.top();
        w2.pop();
    }
}
