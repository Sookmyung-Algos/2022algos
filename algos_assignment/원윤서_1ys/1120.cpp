#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int max_len;
string A, B, tmp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    for (int i = 0; i <= B.size() - A.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < A.size(); j++)
            if (A[j] == B[i + j]) cnt++;
        max_len = max(max_len, cnt);
    }

    cout << A.size() - max_len << '\n';
}
