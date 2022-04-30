#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string A, B;
    int min = 987654321;
    cin>>A>>B;
    for (int i = 0; i + A.length() <= B.length(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < A.length(); j++)
        {
            if (A[j] != B[i + j])
                cnt++;
        }
        if (cnt < min)
            min = cnt;
    }
    cout << min << "\n";
    return 0;
}
