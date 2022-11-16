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

vector<int> mul (vector<int> &v, vector<int> &u)
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
    vector<int> w (S);
    for (int i = 0; i < S; i++) w[i] = round (vc[i].real());

    return w;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int nu, nm, nl;
    cin >> nu;
    vector<int> up (60001, 0);
    vector<int> down(60001, 0);
    for (int i = 0; i < nu; i++) {
        int pos;
        cin >> pos;
        up[pos + 30000]++;
    }
    cin >> nm;
    vector<int> mid(nm);
    for (int i = 0; i < nm; i++) cin >> mid[i];
    cin >> nl;
    for (int i = 0; i < nl; i++) {
        int pos;
        cin >> pos;
        down[pos + 30000]++;
    }
    ll ans = 0;
    vector<int> ret = mul (up, down);
    for (auto& it : mid)
    {
        ans += ret[(it + 30000) * 2];
    }
    cout << ans << "\n";
    return 0;
}
