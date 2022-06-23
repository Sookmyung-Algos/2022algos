#include <iostream> 
#include <string>
#include <unordered_set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s;

    
    while (true) {
        cin >> s;
        if (s == "*") break;
        int isSurprise = 0; 
        for (int i = 1; i <= s.length() - 1; i++) {
            unordered_set<string> v;
            for (int j = 0; j < s.length() - i; j++) {
                string temp;
                temp += s[j];
                temp += s[j + i]; 
                if (v.count(temp) == 0) v.insert(temp);
                else isSurprise++; 
            }   
        }
        if (isSurprise == 0) cout << s << " is surprising.\n";
        else cout << s << " is NOT surprising.\n";
    }
    return 0; 

}
