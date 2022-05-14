#include <iostream>
#include <algorithm>
using namespace std;

int l[11];

int main()
{
    ios::sync_with_stdio(0); //시간초과방지
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i<n; i++)
        cin >> l[i];
    
    reverse(l, l+n);
    int count = 0 ;
    while ( k > 0)
    {
        for (int i = 0; i<n; i++)
        {
            if (k/l[i] > 0)
            {
                count += (k/l[i]);
                k = k - (k/l[i])*l[i]; 
            }
        }
    }
    cout << count;
    return 0;
}
