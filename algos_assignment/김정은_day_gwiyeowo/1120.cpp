#include<iostream>
#include<string>
using namespace std;

int main(){
    int cnt;
    int min = 50;
    string a,b;

    cin >> a >> b;

    for(int leng=0; leng<=b.length() - a.length(); leng++){
        cnt = 0;
        
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i+leng]) cnt++;
        }
        
        min = min>=cnt ? cnt:min;

    }
    cout<<min<<endl;
}
