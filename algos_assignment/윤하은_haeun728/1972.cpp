#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(1){
        cin >> s;
        if(s == "*") return 0;

        bool flag = true;
        for(int d=1; d<s.length(); d++){
            vector<string> v;
            for(int i=0; i<s.length()-d; i++){
                string tmp = "";
                tmp += s[i];
                tmp += s[i+d];
                v.push_back(tmp);
            }
            for(int i=0; i<v.size(); i++){
                for(int j=i+1; j<v.size(); j++){
                    if(v[i] == v[j]){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
        }

        (flag) ? cout << s << " is surprising.\n" : cout << s << " is NOT surprising.\n";
    }

    return 0;
}
