#include <iostream>
#include <algorithm>

using namespace std;

int grundy[2002];
bool visit[202];

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    for (int i = 2; i <= 2000; i++)
    {
        fill (visit, visit+202, false);
        for (int j = 1; j < i; j++)
        {
            int div = i / j;
            int remain = i % j;

            int cur = grundy[remain];
            if (div % 2) {
                cur ^= grundy[j];
            }
            visit[cur] = true;
        }
        for (int j = 0; j < 202; j++)
        {
            if (!visit[j]) {
                grundy[i] = j;
                break;
            }
        }
    }
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int pile;
        cin >> pile;
        ans ^= grundy[pile];
    }
    if (ans) cout << "First\n";
    else cout << "Second\n";
    return 0;
}
