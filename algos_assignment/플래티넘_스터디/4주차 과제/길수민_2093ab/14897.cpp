#pragma GCC optimize ("03")

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 7;
int N, sqrtN;
int Q;
class Query {
public:
    int l, r, num;
    bool operator < (const Query& b)
    {
        if (l / sqrtN == b.l / sqrtN) return r < b.r;
        return l / sqrtN < b.l / sqrtN;
    }
};
vector<Query> qlist;
int cnt[MAX];
vector<int> arr;
vector<int> ans;
int cur;

void make_up (int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (cnt[arr[i]] == 0) cur++;
        cnt[arr[i]]++;
    }
}

void make_down (int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cnt[arr[i]]--;
        if (cnt[arr[i]] == 0) cur--;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    cin >> N;
    arr.resize (N);
    sqrtN = sqrt (N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<int> tmp = arr;
    sort (tmp.begin(), tmp.end());
    tmp.erase (unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < N; i++)
        arr[i] = distance(tmp.begin(), lower_bound (tmp.begin(), tmp.end(), arr[i]));
    cin >> Q;
    qlist.resize (Q);
    ans.resize (Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> qlist[i].l >> qlist[i].r;
        qlist[i].l--;
        qlist[i].r--;
        qlist[i].num = i;
    }
    sort (qlist.begin(), qlist.end());
    make_up (qlist[0].l, qlist[0].r);
    ans[qlist[0].num] = cur;
    int cur_l = qlist[0].l;
    int cur_r = qlist[0].r;
    for (int i = 1; i < Q; i++)
    {
        if (cur_l > qlist[i].l) make_up (qlist[i].l, cur_l - 1);
        if (cur_r < qlist[i].r) make_up (cur_r + 1, qlist[i].r);
        if (cur_r > qlist[i].r) make_down (qlist[i].r + 1, cur_r);
        if (cur_l < qlist[i].l) make_down (cur_l, qlist[i].l - 1);
        cur_l = qlist[i].l;
        cur_r = qlist[i].r;
        ans[qlist[i].num] = cur;
    }
    for (int i = 0; i < Q; i++)
        cout << ans[i] << "\n";
    return 0;
}
