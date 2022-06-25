#include <iostream>
#include <vector>

using namespace std;

long long sum[250001];

int main() {
  int n, m, num;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    scanf("%d", &num);
    if(i==0) {
      sum[i] = num;
      continue;
    }
    sum[i] = sum[i-1] + num;
  }
  
  int count = 1;
  long long maxSum = sum[m-1];
  
  for(int i=m; i<n; i++) {
    if(maxSum < sum[i] = sum[i-m]){
      maxSum = sum[i] - sum[i-m];
      count = 1;
    }
    else if(maxSum == sum[i] - sum[i-X]) {
      count +=1;
    }
  }
  if(maxSum == 0) {
    printf("SAD");
  }
  else {
    printf("&lld\n", maxSum);
    printf("%d", count);
  }
}
