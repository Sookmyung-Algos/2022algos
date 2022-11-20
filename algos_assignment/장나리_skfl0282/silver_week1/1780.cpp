#include <iostream>
using namespace std;

int n[2200][2200];
int result[3];
bool solve(int a,int b,int N){
    int start=n[a][b];
    for(int i=a;i<a+N;i++){
        for(int j=b;j<b+N;j++){
            if(start != n[i][j]){
                return false;
            }
        }
    }
    return true;
}
void divide(int a,int b,int N){
    if(solve(a,b,N)) {
        result[n[a][b]+1]++;
    }
    else {
        int next = N/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                divide(a+next*i,b+next*j,next);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            cin >> n[i][j];
        }
    }
    divide(0,0,N);
    cout << result[0] << "\n";
	cout << result[1] << "\n";
	cout << result[2] << "\n";
}
