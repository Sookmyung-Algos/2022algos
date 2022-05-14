#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, target;
    
    cin >> N;
    
    vector<int> card(N, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }
    
    cin >> M;
    
    sort(card.begin(), card.end());
    
    for (int i = 0; i < M; i++) {
        cin >> target;
        
        int end = upper_bound(card.begin(), card.end(), target) - card.begin();
        int start = lower_bound(card.begin(), card.end(), target) - card.begin();
        
        cout << end - start << " ";
    }
    
    cout << "\n";
    
    return 0;
}
