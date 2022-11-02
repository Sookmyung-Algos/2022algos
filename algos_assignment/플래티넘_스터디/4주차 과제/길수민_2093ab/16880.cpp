#include <bits/stdc++.h>

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int N;
    int grundy = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'R')
            grundy ^= (x^y);
        else if (c == 'B')
            grundy ^= min (x, y);
        else if (c == 'K')
            grundy ^= (min (x, y) % 2) * 2 + ((x + y) % 2);
        else if (c == 'N')
            grundy ^= min (x, y) % 3 - (abs(x - y) < (min(x, y) % 3));
        else
            grundy ^= ((x / 3)^(y / 3)) * 3 + (x + y) % 3;
    }
    if (grundy) cout << "koosaga\n";
    else cout << "cubelover\n";
    return 0;
}
