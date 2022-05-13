#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int len1, len2;
    string str;
    map<char, int> state;
    state['A'] = 0;
    state['C'] = 0;
    state['G'] = 0;
    state['T'] = 0;
    int cnt = 0;
    int index = 0;
    cin >> len1 >> len2;
    cin >> str;
    int A, C, G, T;
    cin >> A >> C >> G >> T;
    map<char, int> require;
    require['A'] = A;
    require['C'] = C;
    require['G'] = G;
    require['T'] = T;
    for (int i = 0; i < len2; i++)
        state[str[i]]++;
    while (index + len2 < len1)
    {
        if (state['A'] >= require['A'] && state['C'] >= require['C'] \
                && state['G'] >= require['G'] && state['T'] >= require['T'])
            cnt++;
        state[str[index]]--;
        state[str[index + len2]]++;
        index++;
    }
    if (state['A'] >= require['A'] && state['C'] >= require['C'] \
            && state['G'] >= require['G'] && state['T'] >= require['T'])
        cnt++;
    cout << cnt << "\n";
    return 0;
}
