#include <iostream>
#include <set>
using namespace std;

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "*")
        {
            break;
        }

        bool flag = false;
        for (int i = 1; i < s.size() && !flag; i++)
        {
            set<string> d_pair;
            int j = 0, k = j + i;
            while (!flag && k < s.size())
            {
                string tmp;
                tmp += s[j];
                tmp += s[k];
                if (!d_pair.empty())
                {
                    if (d_pair.find(tmp) != d_pair.end())
                    {
                        flag = true;
                        cout << s << " is NOT surprising.\n";
                        break;
                    }
                }
                d_pair.insert(tmp);
                j++; k++;
            }
        }
        if (!flag)
        {
            cout << s << " is surprising.\n";
        }
    }
    return 0;
}
