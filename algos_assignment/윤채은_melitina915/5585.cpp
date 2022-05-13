#include <iostream>

using namespace std;

int main(void) {

    int coin[6] = { 500,100,50,10,5,1 };
    int money;

    cin >> money;

    int lift = 1000 - money;
    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        while (lift >= coin[i]) {
            lift -= coin[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
