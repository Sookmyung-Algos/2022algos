#include <iostream>
#include <algorithm>
using namespace std;

int t[100001];

int main(){
    int n, k;
    cin >> n >> k;
    
    for (int i = 0 ; i < n; i++)
        cin >> t[i];
    
    int m = 0;
    
    for (int i = 0; i<k; i++)
        m += t[i];

    int temp = m;
    
    for (int i = k; i < n; i++){
        temp = temp + t[i] - t[i - k];
        if (temp > m)
            m = temp;
    }
    
    cout << m;
        
}
