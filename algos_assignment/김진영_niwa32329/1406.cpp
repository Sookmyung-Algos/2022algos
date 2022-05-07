#include <iostream>
#include <list>
using namespace std; 

int n;
string s; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> n; 
    list<char> lst(s.begin(), s.end()); 
    auto cursor = lst.end(); 

    while (n--) {
        char temp; 
        cin >> temp; 

        if (temp == 'L') {
            if (cursor != lst.begin()) {
                cursor--; 
            }
        }
        else if (temp == 'D') {
            if (cursor != lst.end()) {
                cursor++; 
            }
        }
        else if (temp == 'B') {
            if (cursor != lst.begin()) {
                cursor = lst.erase(--cursor); 
            }
        }
        else if (temp == 'P') {
            char c;
            cin >> c; 
            lst.insert(cursor, c); 
        }
    }

    for (auto i = lst.begin(); i != lst.end(); i++) {
        cout << *i; 
    }

}
