// 여름방학 4일차 B.구간 곱 구하기
#include <iostream>
#include <vector>
#include <cmath>
#define MOD 1000000007
using namespace std;

int N, M, K;  // N: 수의 개수, M: 수의 변경이 일어나는 횟수, K: 구간 곱 구하는 횟수
vector<long long>tree;
vector<long long> numbers;
int a, b, c;  // a: 1이면 b번째 수를 c로 바꾸고, a: 2이면 b부터 c까지 곱 구하기

long long init(int node, int start, int end) {
    if(start == end)
        return tree[node] = numbers[start];
    
    // start != end일 때
    int mid = (start + end) / 2;  // 각 노드의 왼쪽, 오른쪽 자식으로 분리
    long long leftChild = init(node * 2, start, mid);
    long long rightChild = init(node * 2 + 1, mid + 1, end);
    return tree[node] = (leftChild * rightChild)%MOD;
}

long long query(int node, int s, int e, int l, int r) {
    // 현재 탐색 범위가 찾고자 하는 구간과 완전히 겹치지 않는 경우
    if (s > r || e < l)
        return 1;
        
    if(l <= s && e <= r)
        return tree[node];
        
    // 일부만 걸쳐 있는 경우 -> 탐색 더 필요
    int mid = (s + e) / 2;
    return (query(node * 2, s, mid, l, r) * query(node * 2 + 1, mid + 1, e, l, r))%MOD;
}

long long update(int node, int node_left, int node_right, int update_idx, long long val) {
    // update_idx가 현재 탐색 범위를 벗어나는 경우
    if (!(node_left <= update_idx && update_idx <= node_right))
        return tree[node];
    
    // update_idx가 탐색 범위 안에 있을 때
    if(node_left == node_right)
        return tree[node] = val;
    
    int mid = (node_left + node_right) / 2;
    return tree[node] = (update(node * 2, node_left, mid, update_idx, val) * update(node * 2 + 1, mid + 1, node_right, update_idx, val)) % MOD;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    
    numbers.resize(N + 1);
    int treeDepth = (int)ceil(log2(N));
    int treeSize = (1 << (treeDepth + 1));
    tree.resize(treeSize);
    
    for (int i = 1; i <= N; i++)  // 처음 배열의 정수 N개
        cin >> numbers[i];
    
    // 세그먼트 트리 초기화
    init(1, 1, N);

    for (int i = 0; i < M+K; i++) {  // 수 변경 및 곱 구하기
        cin >> a >> b >> c;
        
        if(a == 1){  // 수 변경
            //long long diff = ;
            numbers[b] = c;
            update(1, 1, N, b, c);
        }
        else{  // 곱 구하기
            if(b > c)
                cout << query(1, 1, N, c, b) << "\n";
            else
                cout << query(1, 1, N, b, c) << "\n";
        }
    }

    return 0;
}
