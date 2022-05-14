#include <iostream> 

#include <vector> 

using namespace std; 

int main() { 
  vector<int> yen = {500,100,50,10,5,1}; 
  int pay,count=0; 
  
  cin >> pay; 
  
  pay = 1000-pay;
  
  for(int i =0 ; i<6; i++) { 
    for(;;) { 
      if(pay>=yen[i]) {
        pay-=yen[i]; 
        count++; 
      }
      else break; 
    } 
  } 
  cout<<count; 
}

