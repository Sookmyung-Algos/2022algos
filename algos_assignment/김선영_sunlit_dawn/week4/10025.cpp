#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    
    for (int i = 0; i<n; i++){
        int x, g = 0;
        cin >> g >> x;
        arr[x] = g;
    }
    
    int maxg = 0;
    for (int i = 0; i < 2*k + 1 ; i++){
        maxg += arr[i];
    }
    
    int temp = maxg;
    for (int i = 2*k + 1; i < 1000001 ; i++){
        temp = temp + arr[i] - arr[i - 2*k - 1];
        if (temp > maxg)
            maxg = temp;
    }
    
    cout << maxg;
}
