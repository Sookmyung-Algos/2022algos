#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int grundy[2002];
bool check[101];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;
    grundy[0] = 0;
    grundy[1] = 1;
    grundy[2] = 1;
    grundy[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        fill(check, check+101, false);
        for (int j = 0; j <= i / 2; j++)
        {
            int first = j - 2;
            int second = i - j - 3;
            if (first < 0) first = 0;
            if (second < 0) second = 0;
            check[grundy[first]^grundy[second]] = true;
        }
        for (int j = 0; j < 101; j++)
        {
            if (!check[j])
            {
                grundy[i] = j;
                break;
            }
        }
    }
    cout << (grundy[n]?"1":"2") << "\n";
    return 0;
}
