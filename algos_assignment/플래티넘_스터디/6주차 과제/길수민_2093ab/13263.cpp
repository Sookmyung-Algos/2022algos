#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
typedef pair<pi, pi> pipi;

const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int n;
vector<ll> a;
vector<ll> b;
ll dp[MAX];

struct Line {
    ll m, c;
    double start;
    Line (ll _m, ll _c, double _start) {
        m = _m;
        c = _c;
        start = _start;
    }
    ll calc (ll x)
    {
        return m * x + c;
    }
};

class CHT {
public:
    vector<Line> st;
    int ptr, top;

    CHT() {
        ptr = 0;
        top = 1;
    }

    double cross (const Line& one, const Line& two)
    {
        return (double)(two.c - one.c) / (one.m - two.m);
    }

    void add (ll m, ll c)
    {
        Line tmp = Line(m, c, -1);
        if (st.empty()) st.push_back (tmp);
        else
        {
            while (!st.empty())
            {
                double cross_x = cross (st.back(), tmp);
                tmp.start = cross_x;
                if (cross_x <= st.back().start) st.pop_back();
                else break;
            }
            st.push_back (tmp);
            top = st.size();
            if (ptr >= top) ptr = top - 1;
        }
    }

    ll query (ll value)
    {
        while (ptr + 1 < top && st[ptr + 1].start <= value)
            ptr++;
        return st[ptr].calc (value);
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> n;
    a.resize (n);
    b.resize (n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    CHT *cht;
    cht = new CHT();
    dp[0] = 0;
    cht->add (b[0], dp[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i] = cht->query (a[i]);
        cht->add (b[i], dp[i]);
    }
    cout << dp[n - 1] << "\n";
    delete cht;
    return 0;
}
