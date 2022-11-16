#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 100005
#define INF 987654321

int n;
int result = 0;
int arr[20] = {0,};

bool check(int idx){
    for (int i=0; i<idx; i++){
        if (arr[idx] == arr[i] || idx - i == abs(arr[idx] - arr[i]))
            return false;
    }
    return true;
}

void solve(int idx){
    if (idx == n){
        result++;
        return;
    }
    
    for (int i=0; i<n; i++){
        arr[idx] = i;
        if (check(idx))
            solve(idx+1);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    solve(0);
    cout<<result;
}
