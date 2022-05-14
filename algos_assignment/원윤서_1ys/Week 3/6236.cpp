#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a, b, low, high;
  cin >> a >> b;
  int array[100001];
  
  low=0;
  high=0;
  
  for (int i=0;i<a;i++){
    cin>>array[i];
    low=max(low, array[i]);
    high=high+array[i];
  }
  
  int mid=0;
  
  while(low<=high){
    mid=(low+high)/2;
    int count=1;
    int money=mid;
    for(int i=0; i<a;i++){
      money=money-array[i];
      if(money<=0){
        money=mid-array[i];
        count++;
      }
    }
    
    if (count>b)
      low=mid+1;
    else
      high=mid-1;
  }
  cout<<mid;
  
  return 0;
}
