#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str, num = "";
    int result = 0;
    bool check = false;
    
    cin >> str;
    
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (check)
                result -= stoi(num);
            else
                result += stoi(num);
            
            num = "";
            
            if (str[i] == '-')
                check = true;
        }
        else
            num += str[i];
    }
    cout << result << "\n";

    return 0;
}
