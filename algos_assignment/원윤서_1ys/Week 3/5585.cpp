#include <iostream>
using namespace std;

int main(){
    int pay;
    int change;
    cin >> pay;
    change=1000-pay;
    int count=0;
    
    int yen[]={500, 100, 50, 10, 5, 1};
    
    for (int i=0;i<6;i++){
        while (change>=yen[i]){
            change=change-yen[i];
            count++;
            if (change==0)
                break;
        }
    }
    cout << count;
      
    return 0;
}
