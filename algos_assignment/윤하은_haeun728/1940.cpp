#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> v;
int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int start=0, end=1, cnt=0;
    sort(v.begin(),v.end());
    while(start<=end && end<N) {
        if(v[start] + v[end] == M)
            cnt++;
        if(end==N-1) {
            start++;
            end=start+1; }
        else end++;
    }
    cout << cnt;
}
