#include <iostream>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    list<char> L;
    
    int N;
    
    cin >> s >> N;
    
    for (int i = 0; i < s.size(); i++) {
        L.push_back(s[i]);
    }
    
    auto it = L.end();
    
    for (int i = 0; i < N; i++) {
        char cmd;
        cin >> cmd;
        
        if (cmd == 'L') {
            if (it != L.begin())
                it--;
        }
        
        else if (cmd == 'D') {
            if (it != L.end())
                it++;
        }
        
        else if (cmd == 'B') {
            if (it != L.begin())
                it = L.erase(--it);
        }
        
        else if (cmd == 'P') {
            char c;
            cin >> c;
            L.insert(it, c);
        }
    }
    
    list<char>:: iterator i;
    for (i = L.begin(); i != L.end(); i++) {
        cout << *i;
    }
    cout << "\n";
    
    return 0;
}
