#include <iostream> 
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int result = 50;
    string a, b;
    cin >> a >> b; 
    

    for (int i = 0; i <=b.length()-a.length() ; i++) {
        int count = 0; 
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != b[i + j]) count++; 
        }
        if (count < result) result = count; 
    }

    cout << result;
    return 0; 
}
