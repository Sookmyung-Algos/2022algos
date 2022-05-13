#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    string str;
    int query_num;
    list <char> editor;
    cin >> str;
    for (auto x : str)
        editor.push_back(x);
    cin >> query_num;
    auto cur = editor.end();
    while (query_num--)
    {
        char query;
        cin >> query;
        if (query == 'P')
        {
            char new_val;
            cin >> new_val;
            editor.insert(cur, new_val);
        }
        if (query == 'L')
        {
            if (cur != editor.begin())
                cur--;
        }
        if (query == 'D')
        {
            if (cur != editor.end())
                cur++;
        }
        if (query == 'B')
        {
            if (cur != editor.begin())
                cur = editor.erase(--cur);
        }
    }
    auto it = editor.begin();
    while (it != editor.end())
        cout << *(it++);
    cout << "\n";
    return 0;
}
