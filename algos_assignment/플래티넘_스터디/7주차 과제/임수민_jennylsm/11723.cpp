#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string order;
    int val, BIT = 0; // BIT를 반드시 0으로 초기화 해준다.
    while (m--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> val;
            // or 연산자를 통해 val번째 자리수를 1로 채운다.
            BIT |= (1 << val);
        }
        else if (order == "remove")
        {
            cin >> val;
            // ex) 1000 & ~(1000) = 0000
            BIT &= ~(1 << val);
        }
        else if (order == "check")
        {
            cin >> val;
            if (BIT & (1 << val))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> val;
            // BIT의 val번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // val번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
            BIT ^= (1 << val);
        }
        else if (order == "all")
        {
            // ex) 10000 - 1 = 1111
            BIT = (1 << 21) - 1;
        }
        else if (order == "empty")
        {
            BIT = 0;
        }
    }

    return 0;
}
