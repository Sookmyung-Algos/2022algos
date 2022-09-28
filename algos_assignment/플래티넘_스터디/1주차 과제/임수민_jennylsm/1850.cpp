#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a%b);
}
 
int main() {
    long long a, b;
    cin>>a>>b;
    
    long long g = a > b ? gcd(a, b) : gcd(b, a);
    for(long long i = 0 ; i<g ; i++){
        cout<<1;
    }
    return 0;
}
