#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        string str;

        cin>>str;
        if (str == "*")
            break;
        bool is_surprising = true;
        for (int i = 1; i < str.length(); i++)
        {
            map<pair<char, char>, int> check;
            for (int j = 0; j + i < str.length(); j++)
            {
                pair<char, char> tmp = make_pair(str[j], str[j+i]);
                if (check.find(tmp) != check.end())
                {
                    is_surprising = false;
                    break;
                }
                check.insert(make_pair(tmp, 1));
            }
            if (!is_surprising)
                break;
        }
        cout << str << ((is_surprising)?" is ":" is NOT ") << "surprising.\n";
    }
    return 0;
}
