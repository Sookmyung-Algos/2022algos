#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const int MOD = 1e9 + 7;
int T, N, D;
ll edge[101][22][22];
ll ret[22][22];

void mmult (int arr1, int arr2)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ret[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                ret[i][j] = (((ll)edge[arr1][i][k] * (ll)edge[arr2][k][j]) % MOD + ret[i][j]) % MOD;
            }
        }
    }
}

vector<vector<ll>> mmultV (vector<vector<ll>> &tmp1, vector<vector<ll>> &tmp2)
{
    vector<vector<ll>> res(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                res[i][j] = (((ll)tmp1[i][k] * (ll)tmp2[k][j]) % MOD + res[i][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> mpower (vector<vector<ll>> &arr, int n)
{
    vector<vector<ll>> res;
    if (n == 1) return arr;
    vector<vector<ll>> sub = mpower(arr, n / 2);
    res = mmultV (sub, sub);
    if (n % 2) {
        res = mmultV(res, arr);
    }
    return res;
}

vector<vector<ll>> solve ()
{
    if (D == 0)
    {
        vector<vector<ll>> initial(N, vector<ll>(N, 0));
        for (int i = 0; i < N; i++)
            initial[i][i] = 1;
        return initial;
    }
    vector<vector<ll>> final_edge(N, vector<ll>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            final_edge[i][j] = edge[T - 1][i][j];
    }
    vector<vector<ll>> res(N, vector<ll>(N, 0));
    if (D / T)
        res = mpower (final_edge, D / T);
    else
    {
        for (int i = 0; i < N; i++)
            res[i][i] = 1;
    }
    
    int remain = D % T;
    if (remain) {
        vector<vector<ll>> tmp(N, vector<ll>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                tmp[i][j] = edge[remain - 1][i][j];
        }
        res = mmultV(res, tmp);
    }
    return res;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.tie (NULL);
    
    cin >> T >> N >> D;
    for (int i = 0; i < T; i++)
    {
        int edge_cnt;
        cin >> edge_cnt;
        for (int j = 0; j < edge_cnt; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge[i][a - 1][b - 1] = c;
        }
        if (i > 0) {
            mmult(i - 1, i);
            for (int k = 0; k < N; k++)
            {
                for (int l = 0; l < N; l++)
                    edge[i][k][l] = ret[k][l];
            }
        }
    }
    vector<vector<ll>> ans = solve();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
