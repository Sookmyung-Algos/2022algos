#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int an, bn, dp[1001][1001];
char a[1001], b[1001];
int find_cnt(int x, int y){
    if(x == an || y == bn)
        return 0;
    int &ret = dp[x][y];
    if(ret != -1)
        return ret;
    ret = max(find_cnt(x, y + 1), find_cnt(x + 1, y));
    if(a[x] == b[y]) 
        ret = 1 + find_cnt(x + 1, y + 1); 
    return ret;
}
void find_lcs(int x, int y){
    if(x == an || y == bn)
        return;
    if(a[x] == b[y]){
        printf("%c", a[x]);
        find_lcs(x + 1, y + 1);
    }
    else if(dp[x + 1][y] == dp[x][y])
        find_lcs(x + 1, y);
    else find_lcs(x, y + 1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    an = strlen(a), bn = strlen(b);
    printf("%d", find_cnt(0, 0));
    find_lcs(0, 0);
}
