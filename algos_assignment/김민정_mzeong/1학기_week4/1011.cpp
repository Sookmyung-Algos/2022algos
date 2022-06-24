#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--){
        int x, y; cin >> x >> y;
        int d = y - x;
        long sd = sqrt(d);
        
        int ans = 2 * sd;
        long mid = ((sd+1)*(sd+1) + sd*sd) / 2; 
        if (d == sd * sd) ans--;
        else if (d > mid) ans++;
        cout << ans << "\n";
    }
    return 0;
}
