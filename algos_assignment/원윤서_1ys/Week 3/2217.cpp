#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num;
    cin >> num;
    
    int rope[num];
    for (int i=0; i<num; i++)
        cin >> rope[i];
    
    sort(rope, rope+num);
    
    int weight=0;
    for (int i=0; i<num; i++){
        if(weight < rope[i]*(num-i))
            weight=rope[i]*(num-i);
    }
    
    cout << weight;
    
    return 0;

}
