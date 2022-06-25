#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()

using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int     main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    i64 part_sum = 0;
    for (int i = 0; i < m; i++)
        part_sum += v[i];

    i64 max_sum = part_sum;
    for (int r = m; r < n; r++)
    {
        part_sum += v[r];
        part_sum -= v[r - m];

        if (max_sum < part_sum)
            max_sum = part_sum;
    }

    cout << max_sum << endl;

    return 0;
}
