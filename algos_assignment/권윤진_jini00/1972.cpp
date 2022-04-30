#include <iostream>
#include <set>

using namespace std;

int main() {
    string str;
    
    while (true) {
        cin >> str;
        
        if (str == "*")
            break;
        
        bool check = true;
        
        for (int i = 1; i < str.length(); i++) {
            set <string> v;
            
            for (int j = 0; j < str.size() - i; j++) {
                string temp;
                
                temp += str[j];
                temp += str[j+i];
                
                if (v.count(temp) == 0)
                    v.insert(temp);
                
                else
                    check = false;

            }
        }
        
        if (check == true)
            cout << str << " is surprising." << "\n";
        else
            cout << str << " is NOT surprising." << "\n";
            
    }
    return 0;
}
