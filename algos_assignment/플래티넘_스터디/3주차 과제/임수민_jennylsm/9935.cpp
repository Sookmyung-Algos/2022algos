#include <iostream>
#include <string>




using namespace std;



int main() {

    string s,bomb;
    cin>>s>>bomb;

    string answer = "";

    int bombIdx = bomb.length()-1;
    for(int i = 0; i < s.length(); i++){
        
        answer += s[i];

        if(answer[answer.length()-1] == bomb[bombIdx]){
            
            if(answer.length() >= bomb.length()){
                int cnt = 1;
            
                for(int j = bombIdx-1; j >= 0; j--){
                    if(answer[answer.length()- (bombIdx-j)-1] == bomb[j]){
                        cnt++;
                    }

                }

                if(bomb.length() == cnt){
                    for(int b = 0; b < bomb.length(); b++){
                        answer.pop_back();
                    }


                }

            }
            
        

        }



    }
    
    
    
    if(answer.length()>0){
        cout<<answer<<endl;
    }
    else{
        cout<<"FRULA"<<endl;
    }


	return 0;
}
