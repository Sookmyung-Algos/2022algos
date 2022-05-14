#include <iostream
#include <string>
using namespace std;

int main(){
  string str;
  cin >> str;
  
  int result=0;
  int n=0;
  string temp="";
  
  for(int i=0; i<=str.size(); i++){
    if(str[i]=='+' || str[i]=='-' || str[i]=='\0'){
      if (n)
        result=result-stoi(temp);
      
      else
        result=result+stoi(temp);
      
      temp="";
      
      if(str[i]=='-')
        n=1;
      continue;
    }
    
    temp=temp+str[i];
      
  cout << result;
  return 0;
}
