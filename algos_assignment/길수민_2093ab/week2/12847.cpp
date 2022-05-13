#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long int> prefix_sum(n);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (i == 0) {
            prefix_sum[i] = input;
            continue;
        }
        prefix_sum[i] = prefix_sum[i - 1] + input;
    }
    int start = 0;
    long long int maxVal = prefix_sum[m - 1];
    while (start + m < n) {
        maxVal = max (maxVal, prefix_sum[start + m] - prefix_sum[start]);
        start++;
    }
    cout << maxVal << "\n";
    return 0;
}
