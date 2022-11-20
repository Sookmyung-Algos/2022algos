#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a;
int k;
int main()
{
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> k;

    int num= n / k;

    for (int i = 0; i < n; i+=num) {
        sort(v.begin() + i, v.begin() + i + num);
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }

}
