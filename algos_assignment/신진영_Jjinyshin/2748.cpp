#include <iostream>
using namespace std;
long long fibo_arr[100] = {0,1,};

long long fibo(int N){
    if(N == 0 || N == 1)
        return fibo_arr[N];
    else if(fibo_arr[N] == 0)
        fibo_arr[N] = fibo(N-1) + fibo(N-2);
    return fibo_arr[N];
}
int main(){
    int N;
    cin >> N;
    cout << fibo(N);
}
