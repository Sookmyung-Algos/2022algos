#include <iostream>
#include <algorithm>

using namespace std;

int n, n_weight[31]; // 추의 개수, 추의 무게
int m, m_weight[7]; // 구슬의 개수, 구슬의 무게
bool dp[31][15001];

void knapsack(int i,int w){
    
    if (i>n || dp[i][w]) return; 
    dp[i][w] = true; // 
    
    knapsack(i+1,w+n_weight[i]); // 구슬 반대쪽 저울에 올리는 경우
    knapsack(i+1,abs(w-n_weight[i])); // 구슬 쪽 저울에 올리는 경우
    knapsack(i+1,w); // 아무것도 하지 않을 경우
}

int main() {
    
    // 추의 개수와 추의 무게 입력 받기
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> n_weight[i];
    }
    knapsack(0,0);
    
		// 구슬의 개수와 구슬의 무게 입력받기
    cin >> m;
    for (int i=0;i<m;i++){
        cin >> m_weight[i];
        
        if (m_weight[i]>15000) cout << "N ";
        else if (dp[n][m_weight[i]]) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}
