#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    int k, m;

    cin >> k >> m;
    for (int i = 0; i < k; i++)
    {
        l.push_back(i + 1);
    }

    list<int>::iterator it;
    while (m--)
    {
        int r, i = 1;
        cin >> r;
        it = l.begin();
        while (it != l.end())
        {
            if (i % r == 0)
            {
                it = l.erase(it++);
            }
            else
                it++;
            i++;
        }
    }
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << "\n";
    }
}
