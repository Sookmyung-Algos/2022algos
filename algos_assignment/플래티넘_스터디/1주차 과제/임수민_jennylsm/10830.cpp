#include <cstdio>
#define mod 1000
using namespace std;
class matrix{
public:
    long long row, column;
    int a[5][5];
    matrix(long long n){
        row = column = n;
        for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) a[i][j] = 0;
    }
    matrix operator* ( matrix o ){
        matrix ret(o.row);
        for( int i=0; i<row; i++ ){
            for( int j=0; j<column; j++ ){
                for( int k=0; k<row; k++ ){
                    ret.a[i][j]+=a[i][k]*o.a[k][j];
                }
                ret.a[i][j]%=mod;
            }
        }
        return ret;
    }
};

int main(){
    long long n, k; scanf("%lld%lld", &n, &k);
    matrix M(n);
    for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) scanf("%d", &M.a[i][j]);
    matrix E(n);
    for( int i=0; i<n; i++ ) E.a[i][i] = 1;
    while( k ){
        if(k&1) E = E * M;
        M = M * M;
        k>>=1;
    }
    for( int i=0; i<n; i++ ){
        for( int j=0; j<n; j++ ) printf("%d ", E.a[i][j]%mod);
        puts("");
    }
    return 0;
}
