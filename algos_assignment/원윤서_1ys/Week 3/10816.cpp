#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, M;
  cin >> N;
  
  vector<int> v1(N);
  
  for (int i=0; i<N; i++)
    cin >> v1[i];
  sort(v1.begin(), v1.end());
  cin >> N;
  
  vector<int> v2(N);
  for (int i=0; i<N; i++){
    cin >> M;
    auto upper = upper_bound(v2.begin(), v2.end(), M);
    auto lower = lower_bound(v2.begin(), v2.end(), M);
    v2[i]=upper-lower;
  }
  for (auto n : answer)
    cout << n << " ";
  
  return 0;
}
