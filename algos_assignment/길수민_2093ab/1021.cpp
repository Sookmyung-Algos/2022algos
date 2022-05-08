#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    deque<int> q;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        q.push_back(i);
    for (int i = 0; i < M; i++)
    {
        int findNum;
        cin >> findNum;
        auto it = find (q.begin(), q.end(), findNum);
        int tmp = it - q.begin();
        tmp = min (tmp, (int)q.size() - tmp);
        if (tmp != it - q.begin())
        {
            cnt += tmp;
            while (tmp--)
            {
                q.push_front(q.back());
                q.pop_back();
            }
        }
        else
        {
            cnt += tmp;
            while (tmp--)
            {
                q.push_back(q.front());
                q.pop_front();
            }
        }
        q.pop_front();
    }
    cout << cnt << "\n";
    return 0;
}
