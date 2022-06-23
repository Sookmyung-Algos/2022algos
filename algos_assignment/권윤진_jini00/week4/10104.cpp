#include <iostream>
#include <list>

using namespace std;

int main() {
    int K, M, r, num;
    list<int> L;
    
    cin >> K >> M;
    
    for (int i = 0; i < K; i++) {
        L.push_back(i+1);
    }
    
    list<int>:: iterator i;
    while (M != 0) {
        cin >> r;
        
        i = L.begin();
        num = 1;
        
        while (i != L.end()) {
            if (num % r == 0)
                i = L.erase(i++);
            else
                i++;
            num++;
        }
        M--;
    }
    
    for (i = L.begin(); i != L.end(); i++) {
        cout << *i << "\n";
    }
    
    return 0;
}
