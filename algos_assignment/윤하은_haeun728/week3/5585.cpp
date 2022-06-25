#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int input, rest[6] = {500, 100, 50, 10, 5, 1}, num = 0;
    cin >> input;
    input = 1000 - input;
    
    for(int i = 0; i < 6; i++){
        if(input / rest[i] != 0){
            int value = input / rest[i];
            input -= value * rest[i];
            num += value;
        }
    }
    
    cout << num << endl;
}
