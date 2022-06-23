#include <iostream>
#include <queue>
#include <functional>
using namespace std; 

int n, a; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin >> n; 

    priority_queue<int, vector<int>, greater<int>> q; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (q.size() > n) q.pop(); 
            cin >> a; 
            q.push(a); 
        }
    }

    do {
        q.pop();
    } while (q.size() == n + 1); 

    cout << q.top(); 
    
   
}
