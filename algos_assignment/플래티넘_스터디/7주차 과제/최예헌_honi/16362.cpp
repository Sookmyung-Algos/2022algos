#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 1002
#define INF 987654321

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    string str;
    stack <char> s;      // 'a' : alpha , 'o' : operator
    bool check = true;   // proper 여부
    
    getline(cin, str);

    int totala = 0;
    int totalo = 0;
    int totalp = 0;
    for (int i=0; i<str.size(); i++){
        // left parentheses
        if (str[i] == '('){
            if (!s.empty() && s.top() == 'a'){
                cout<<"error";
                return 0;
            }
            s.push(str[i]);
            totalp++;
        }
        
        // right parentheses
        else if (str[i] == ')'){
            totalp++;
            if (s.top() == 'o' || s.empty()){
                cout<<"error";
                return 0;
            }
            
            int cnta = 0;
            int cnto = 0;
            int cntl = 0;
            
            while (true){
                if (s.empty())
                    break;
                
                char temp = s.top();
                s.pop();
                
                if (temp == '('){
                    cntl++;
                    break;
                }
                
                else if (temp == 'a')
                    cnta++;
                
                else if (temp == 'o')
                    cnto++;
            }
            
            // error
            if (cntl == 0){     // a+a)
                cout<<"error";
                return 0;
            }
            
            // improper : (a) , (a+a+a)
            if (cnta != 2 || cnto != 1)
                check = false;
            
            if (cnta != 0 || cnto != 0)
                s.push('a');
        }
        
        // operand
        else if ('a' <= str[i] && str[i] <= 'z'){
            totala++;
            if (!s.empty() && s.top() == 'a'){
                cout<<"error";
                return 0;
            }
            else{
                s.push('a');
            }
        }
        
        // operator
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'){
            totalo++;
            if (!s.empty() && s.top() == 'a'){
                s.push('o');
            }
            else{
                cout<<"error";
                return 0;
            }
        }
        
        else if (str[i] == ' ')
            continue;
    }
    
    if (totala == 1 && totalo == 0 && totalp == 0){
        cout<<"proper";
        return 0;
    }
    
    int cnta = 0;
    int cnto = 0;
    int cnte = 0;
    while (true){
        if (s.empty())
            break;
        
        char temp = s.top();
        s.pop();
        
        if (temp == 'a')
            cnta++;
        
        else if (temp == 'o')
            cnto++;
        
        else
            cnte++;
    }
    
    if (cnte > 0 || cnto >= cnta)
        cout<<"error";
    else if (check && cnta == 2 && cnto == 1)
        cout<<"proper";
    else
        cout<<"improper";
    
    return 0;
}

