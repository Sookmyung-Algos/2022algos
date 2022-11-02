#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n, len, lr;
    int dir[4]={0,};
    int temp, nx=0, ny=0;
    
    cin>>n;
    
    temp = 1;
    for (int i=0;i<n;i++){
        int distance = 0;
        int next = 0;
        
        cin>>len>>lr;
        
        if (temp == 0){
            next = max(dir[temp], ny) + 1;
            distance = next - ny;
            ny = next;
            dir[temp] = ny;
        }
        
        else if (temp == 1){
            next = max(dir[temp], nx) + 1;
            distance = next - nx;
            nx = next;
            dir[temp] = nx;
        }
        
        else if (temp == 2){
            next = min(dir[temp], ny) - 1;
            distance = ny - next;
            ny = next;
            dir[temp] = ny;
        }
        
        else if (temp == 3){
            next = min(dir[temp], nx) - 1;
            distance = nx - next;
            nx = next;
            dir[temp] = nx;
        }
        
        cout<<distance<<" ";
        temp += lr;
        while (temp<0)
            temp+=4;
        temp%=4;
    }
}
