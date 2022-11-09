#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

class Matrix {
    int n;
    bool no_ans;
    bool matrix[505][1010];
public:
    Matrix (int _n) {
        n = _n;
        no_ans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
            for (int j = 0; j < n; j++)
                matrix[i][n + j] = (i == j) ? true : false;
        }
    }

    void swap_row (int row1, int row2)
    {
        bool tmp[1010];
        for (int i = 0; i < 2 * n; i++)
            tmp[i] = matrix[row1][i];
        for (int i = 0; i < 2 * n; i++)
            matrix[row1][i] = matrix[row2][i];
        for (int i = 0; i < 2 * n; i++)
            matrix[row2][i] = tmp[i];
    }
    
    void get_inv ()
    {
        for (int i = 0; i < n; i++)
        {
            if (!matrix[i][i])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (matrix[j][i]) {
                        swap_row (i, j);
                        break;
                    }
                }
                if (!matrix[i][i])
                {
                    no_ans = true;
                    break;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (matrix[j][i])
                {
                    for (int k = 0; k < 2 * n; k++)
                        matrix[j][k] = matrix[i][k] ^ matrix[j][k];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (!matrix[i][i]) break;
            for (int j = i - 1; j >= 0; j--)
            {
                if (matrix[j][i])
                {
                    for (int k = 0; k < 2 * n; k++)
                        matrix[j][k] = matrix[i][k] ^ matrix[j][k];
                }
            }
        }
    }

    void solve ()
    {
        if (no_ans)
        {
            cout << "-1\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j + n])
                    cout << j + 1 << " ";
            }
            cout << "\n";
        }
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;
    Matrix matrix(n);
    matrix.get_inv();
    matrix.solve();
    return 0;
}

