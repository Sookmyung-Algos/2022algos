#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;
typedef complex<double> cpx;

const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void FFT (vector<cpx> &v, bool inv)
{
    int S = v.size();

    for (int i = 1, j = 0; i < S; i++)
    {
        int bit = S / 2;
        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;
        if (i < j) swap (v[i], v[j]);
    }

    for (int k = 1; k < S; k *= 2)
    {
        double angle = (inv ? PI / k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for (int i = 0; i <S; i+= k*2) {
            cpx z(1, 0);

            for (int j = 0; j < k; j++)
            {
                cpx even = v[i + j];
                cpx odd = v[i + j + k];

                v[i + j] = even + z * odd;
                v[i + j + k] = even - z * odd;
                z *= w;
            }
        }
    }

    if (inv)
        for (int i = 0; i < S; i++) v[i] /= S;
}

vector<ll> mul (vector<ll> &v, vector<ll> &u)
{
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    int S = 2;
    while (S < v.size() + u.size()) S *= 2;

    vc.resize (S);
    FFT (vc, false);
    uc.resize (S);
    FFT (uc, false);

    for (int i = 0; i < S; i++) vc[i] *= uc[i];
    FFT (vc, true);
    vector<ll> w (S);
    for (int i = 0; i < S; i++) w[i] = round (vc[i].real());

    return w;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    string num1, num2;
    cin >> num1 >> num2;
    int N, M;
    N = num1.length();
    M = num2.length();
    vector<ll> v(N), u(M);
    for (int i = 0; i < N; i++) v[i] = num1[i] - '0';
    for (int i = 0; i < M; i++) u[i] = num2[i] - '0';

    vector<ll> w = mul (v, u);
    for (int i = v.size() + u.size() - 2; i > 0; i--)
    {
        w[i - 1] += w[i] / 10;
        w[i] %= 10;
    }
    for (int i = 0; i < v.size() + u.size() - 1; i++) cout << w[i];
    cout << "\n";
    return 0;
}
