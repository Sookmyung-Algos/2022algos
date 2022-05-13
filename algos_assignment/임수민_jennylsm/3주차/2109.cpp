#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
int n;
priority_queue<int, vector<int>, greater<int>> pq; //최솟값이 루트로 가는 우선순위큐
vector<pair<int, int>> v; //d, p 저장 벡터
int result; // 출력
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        v.push_back(make_pair(d, p)); //day 순으로 정렬하기 위해 d, p로 저장
    }
 
    sort(v.begin(), v.end());
 
    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);
        result += v[i].second;
 
        if (pq.size() > v[i].first) {
            result -= pq.top();
            pq.pop();
        }
    }
    
    cout << result;
 
    return 0;
}
