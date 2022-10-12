#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

class TRIE {
    bool finish;
    int kinds;
    bool onlyOne;
    int cnt;
    vector<pair<char, TRIE*>> child;
public:    TRIE ()
    {
        kinds = 0;
        finish = false;
        onlyOne = true;
        cnt = 0;
    }

void insert (string &str, int index)
    {
        cnt++;
        if (index == str.size())
        {
            finish = true;
            kinds++;
            return;
        }
        int cur = str[index] - 'A';
        for (auto& ch: child)
        {
            if (ch.first == cur)
            {
                onlyOne = false;
                ch.second->insert(str, index + 1);
                return;
            }
        }
            kinds++;
        child.push_back ({ cur, new TRIE() });
        child.back().second->insert(str, index + 1);
    }

ll getSize ()
    {
        ll tmp = 1;
        ll cur = 1;
        if (finish && kinds == 1) return 1;
        for (int i = 1; i <= kinds; i++)
            tmp = (tmp * i) % MOD;
        /*for (int i = 0; i < 26; i++)
        {
            if (child[i]) {
                tmp *= child[i]->getSize();
                tmp %= MOD;
                //tmp *= cur;
                //cur++;
                //tmp %= MOD;
            }
        }*/
        for (auto& ch: child)
        {
            tmp *= ch.second->getSize();
            tmp %= MOD;
        }
        return tmp;
    }
};

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int N;
    cin >> N;
    TRIE root;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        root.insert (str, 0);
    }
    cout << root.getSize() << "\n";
    return 0;
}
