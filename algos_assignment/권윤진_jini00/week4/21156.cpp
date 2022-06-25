#include <iostream>
#include <list>

using namespace std;

int main() {
    int N, M;
    list<int> L;
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        L.push_back(i);
    }
    
    list<int>:: iterator it;
    for (int i = 0; i < M; i++) {
        string t1, t2;
        cin >> t1 >> t2;
        
        it = L.begin();
        
        int winner = stoi(t1.substr(1));
        int loser = stoi(t2.substr(1));
        int flag = 0, check = 0;
        
        for (auto it = L.begin(); it != L.end(); it++) {
            if (*it == loser && flag == 1) {
                check = 1;
                break;
            }
            else if (*it == winner) {
                flag = 1;
            }
        }
        
        if (check == 0) {
            while (it != L.end()) {
                if (*it == loser) {
                    it = L.erase(it++);
                }
                
                else if (*it == winner) {
                    L.insert(++it, loser);
                }
                
                else {
                    it++;
                }
            }
        }
    }
    
    for (auto it = L.begin(); it != L.end(); it++) {
        cout << "T" << *it << " ";
    }
    
    cout << "\n";
    
    return 0;
}
