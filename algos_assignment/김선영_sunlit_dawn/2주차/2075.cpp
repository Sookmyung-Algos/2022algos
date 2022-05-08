#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[2250010]; //메모리제한
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
  
    int n;
    cin >> n;
  
    for (int i = 0; i < n * n; i++)
        cin >> v[i];
    
    sort(v, v + n * n);
    cout << v[n * n - n] << endl;
    return 0;
}
