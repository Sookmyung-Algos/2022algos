#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inv, ans;

class TRIE {
    int base;
    TRIE* child[2];
public:
    TRIE(int _base) {
        base = _base;
        child[0] = NULL;
        child[1] = NULL;
    }

    ~TRIE() {
        if (child[0]) delete child[0];
        if (child[1]) delete child[1];
    }

    void insert (int num)
    {
        if (base == 0) return;
        int cur = num / base;
        if (!child[cur]) child[cur] = new TRIE(base / 2);
        child[cur]->insert (num % base);
    }

    void find (int num)
    {
        if (base == 0) return;
        int cur = num / base;
        int rev = 1 - cur;
        if (child[rev])
        {
            inv += rev * base;
            child[rev]->find (num % base);
        }
        else
        {
            inv += cur * base;
            child[cur]->find (num % base);
        }
    }

};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        TRIE root((int)1 << 30);
        int cur = 0;
        vector<int> prefix_sum = {0};
        root.insert (0);
        for (int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            cur ^= num;
            prefix_sum.push_back (cur);
            root.insert (cur);
        }
        ans = 0;
        for (auto& it: prefix_sum)
        {
            inv = 0;
            root.find (it);
            int ret = inv ^ it;
            ans = max (ans, ret);
        }
        cout << ans << "\n";
    }
    return 0;
}
