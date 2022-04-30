#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second; 
}

int main() {
    int n;
    int result = 1;
    vector<pair<int, int>> s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        s.push_back(pair<int,int>(a,b));
    }

    sort(s.begin(),s.end(),compare);

    int t = s[0].second;
    for (int i = 1; i < n; i++) {
        if (t <= s[i].first) {
            result++; 
            t = s[i].second; 
        }
    }
    
    cout << result; 
    

}
