#include<iostream>

#define MAX 1001
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> Arr[i];
    }
    
    for (int i = 1; i <= N; i++){
        DP[i] = 1;
        for (int j = 1; j <= i; j++){
            if (Arr[i] < Arr[j] && DP[j] + 1 > DP[i]){
                DP[i] = DP[j] + 1;
            }
        }
    }
 
    int Max = 0;
    for (int i = 1; i <= N; i++){
        if (DP[i] > Max){
            Max = DP[i];
        }    
    }
    cout << Max << "\n";
    

    return 0;
}
