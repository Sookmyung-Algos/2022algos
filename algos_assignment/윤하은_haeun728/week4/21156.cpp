#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
void fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    fast_io();
    list<int> l;
    std::list<int>::iterator it;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        l.push_back(i);
    while (m--)
    {
        it = l.begin();
        string a, b;
        cin >> a >> b;
        int winner = stoi(a.substr(1));
        int loser = stoi(b.substr(1));
        int i = 0, ck = 0;
        for (auto it = l.begin(); it != l.end(); it++)
        {
            if (*it == loser && i == 1)
            {
                ck = 1;
                break;
            }
            else if (*it == winner)
                i = 1;
        }
        if (ck == 0)
        {
            while (it != l.end())
            {
                if (*it == loser)
                {
                    it = l.erase(it++);
                }
                else if (*it == winner)
                {
                    l.insert(++it, loser);
                }
                else
                {
                    it++;
                }
            }
        }
    }
    for (auto it = l.begin(); it != l.end(); it++)
        cout << "T" << *it << " ";
}
