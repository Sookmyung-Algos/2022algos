#include <iostream>
#include <set>
using namespace std;
unsigned int N, M;
multiset <long long> S;
void Print(){
    multiset<long long>::iterator iter;
    for(iter=S.begin();iter!=S.end();iter++)
        cout << *iter << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0;i<N;i++){
        long long n;
        cin >> n;
        S.insert(n);
    }

    for(int i=0;i<M;i++){
        long long n;
        cin >> n;
        S.insert(n);
    }
    Print();
    return 0;
}
