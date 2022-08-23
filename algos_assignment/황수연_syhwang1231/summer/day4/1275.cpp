// 여름방학 4일차 C.커피숍2
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, Q;  // N: 수의 개수, Q: 턴의 개수
vector<long long>tree;
vector<long long> numbers;
int x, y, a;  // x~y의 합, a번째 수를 b로 바꾸기
long long b;

long long init(int node, int start, int end) {
    if(start == end)
        return tree[node] = numbers[start];
    
    // start != end일 때
    int mid = (start + end) / 2;  // 각 노드의 왼쪽, 오른쪽 자식으로 분리
    long long leftChild = init(node * 2, start, mid);
    long long rightChild = init(node * 2 + 1, mid + 1, end);
    return tree[node] = leftChild + rightChild;
}

long long query(int node, int s, int e, int l, int r) {
    // 현재 탐색 범위가 찾고자 하는 구간과 완전히 겹치지 않는 경우
    if (s > r || e < l)
        return 0;
        
    if(l <= s && e <= r)
        return tree[node];
        
    // 일부만 걸쳐 있는 경우 -> 탐색 더 필요
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int node_left, int node_right, int update_idx, long long diff) {
    // update_idx가 현재 탐색 범위를 벗어나는 경우
    if (!(node_left <= update_idx && update_idx <= node_right))
        return;
    
    // update_idx가 탐색 범위 안에 있을 때
    tree[node] += diff;
    
    if (node_left != node_right) {
        int mid = (node_left + node_right) / 2;
        update(node * 2, node_left, mid, update_idx, diff);
        update(node * 2 + 1, mid + 1, node_right, update_idx, diff);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    
    numbers.resize(N + 1);
    int treeDepth = (int)ceil(log2(N));
    int treeSize = (1 << (treeDepth + 1));
    tree.resize(treeSize);
    
    for (int i = 1; i <= N; i++)  // 처음 배열의 정수 N개
        cin >> numbers[i];
    
    // 세그먼트 트리 초기화
    init(1, 1, N);

    for (int i = 0; i < Q; i++) {  // 각각의 턴
        cin >> x >> y >> a >> b;
        
        long long diff = b - numbers[a];  // 차이
        
        if (x > y){
            cout << query(1, 1, N, y, x) << "\n";
        }
        else{
            cout << query(1, 1, N, x, y) << "\n";
        }
        numbers[a] = b;
        update(1, 1, N, a, diff);
    }

    return 0;
}
