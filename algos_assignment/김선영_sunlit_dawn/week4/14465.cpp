#include <iostream>
#include <algorithm>
using namespace std;

int line[100001] = {};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, b;
    cin >> n >> k >> b;
    
    for (int i = 0; i<b ; i++){
        int temp;
        cin >> temp;
        line[temp-1] = 1;
    }    
    
    int m = 0;
    
    for (int i = 0; i<k ; i++)
        m += line[i];
    
    int temp = m;
    for(int i = k; i<n+1; i++){
        temp = temp + line[i] - line[i - k];
        if (m > temp)
            m = temp;
    }
    
    cout << m;
}
