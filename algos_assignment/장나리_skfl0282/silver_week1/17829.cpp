#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[1025][1025];

int solve(int x, int y)
{
    vector<int> v;
    for (int i = x; i < x + 2; i++) {
        for (int j = y; j < y + 2; j++) {
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[2];

}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (n > 1) {
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < n; j += 2) {
                a[i / 2][j / 2] = solve(i, j);
            }
        }
        n /= 2;

    }
    cout << a[0][0] << "\n";
}
