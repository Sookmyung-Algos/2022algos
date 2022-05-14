#include <iostream>

using namespace std;

int main() {
    int money, change, temp, cnt = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    
    cin >> money;
    
    change = 1000 - money;
    
    for (int i = 0; i < 6; i++) {
        temp = change / coin[i];
        
        if (temp != 0) {
            cnt += temp;
        }
        
        change %= coin[i];
    }
    
    cout << cnt << "\n";
    
    return 0;
}
