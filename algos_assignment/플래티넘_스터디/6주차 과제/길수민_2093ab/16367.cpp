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

class SCC {
public:
    int n;
    vector<vector<int>> edge;
    int id, sccNum;
    vector<int> scc_id;
    vector<bool> finish;
    stack<int> st;
    vector<int> group_id;

    SCC (int _n) {
        n = _n;
        scc_id.assign (n * 2, 0);
        finish.assign (n * 2, false);
        edge.resize (n * 2);
        group_id.assign (n * 2, 0);
        id = 0;
        sccNum = 0;
    }

    int get_index (int lamp, bool is_not)
    {
        return lamp * 2 - (is_not ? 1 : 2);
    }

    int not_index (int index)
    {
        if (index % 2) return index - 1;
        else return index + 1;
    }

    void add (int *lamp, char *color)
    {
        int num[3];
        for (int i = 0; i < 3; i++)
            num[i] = get_index (lamp[i], color[i] == 'B');
        edge[not_index(num[0])].push_back (num[1]);
        edge[not_index(num[0])].push_back (num[2]);
        edge[not_index(num[1])].push_back (num[0]);
        edge[not_index(num[1])].push_back (num[2]);
        edge[not_index(num[2])].push_back (num[0]);
        edge[not_index(num[2])].push_back (num[1]);
    }

    int dfs (int node)
    {
        scc_id[node] = ++id;
        st.push (node);

        int parent = scc_id[node];
        for (auto& next: edge[node])
        {
            if (!scc_id[next]) parent = min (parent, dfs (next));
            else if (!finish[next]) parent = min (parent, scc_id[next]);
        }
        if (parent == scc_id[node])
        {
            sccNum++;
            while (true)
            {
                int topNode = st.top();
                st.pop();
                group_id[topNode] = sccNum;
                finish[topNode] = true;
                if (topNode == node) break;
            }
        }
        return parent;
    }

    void make_scc()
    {
        for (int i = 0; i < 2 * n; i++)
            if (!finish[i]) dfs (i);
    }

    bool check_ok()
    {
        for (int i = 0; i < n; i++)
        {
            if (group_id[2 * i] == group_id[2 * i + 1])
                return false;
        }
        return true;
    }

    void printAns ()
    {
        for (int i = 0; i < n; i++)
        {
            if (group_id[i * 2] < group_id[i * 2 + 1])
                cout << 'R';
            else cout << 'B';
        }
        cout << "\n";
    }
};


int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int k, n;
    cin >> k >> n;
    SCC *scc;
    scc = new SCC(k);
    for (int i = 0; i < n; i++)
    {
        int lamp[3];
        char color[3];
        cin >> lamp[0] >> color[0];
        cin >> lamp[1] >> color[1];
        cin >> lamp[2] >> color[2];
        //cout << lamp[0] << lamp[1] << lamp[2] << "\n";
        //cout << color << "\n"
        scc->add (lamp, color);
    }

    scc->make_scc();
    bool ret = scc->check_ok();
    if (ret) scc->printAns();
    else cout << "-1\n";
    delete scc;
    return 0;
}
