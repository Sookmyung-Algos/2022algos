#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num;
    cin>>num;
    for(int i = 0; i < num; i++)
    {
        long long x,y;
        long long move,max = 0;
        cin >>x>>y;
        while(max*max <= y-x)
            max++;
        max--;
        move = 2*max -1;
        long long a = y-x - max*max;
        a = (long long)ceil((double)a/ (double)max);
        move += a;
        cout<<move<<"\n";
    }
}
