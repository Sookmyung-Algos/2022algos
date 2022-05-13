#include <iostream>

using namespace std;

int main(void) {

    int coin[6] = { 500,100,50,10,5,1 };
    int money;

    cin >> money;

    int remain = 1000 - money;
    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        while (remain >= coin[i]) {
            remain -= coin[i];
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
