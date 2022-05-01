#include <iostream>

using namespace std;

int main()
{
    string a, b;
    int min = 50;

    cin >> a >> b;

    for (int i = 0; i <= b.length() - a.length(); i++)
    {
        int count = 0;

        for (int j = 0; j < a.length(); j++)
        {
            if (a[j] != b[i + j])
                count++;
        }

        if (count < min)
            min = count;
    }

    cout << min;

}
