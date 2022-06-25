#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<iostream>
using namespace std;

void solution() {
    int N, M;
    int temp;
    unordered_map<int, int> num_cards;

    cin >> N;

    for (int i = 0;i < N;i++) {
        scanf("%d", &temp);
        num_cards[temp]++;
    }

    cin >> M;

    for (int i = 0;i < M;i++) {
        scanf("%d", &temp);
        printf("%d ", num_cards[temp]);
    }
}

int main() {
    solution();
    return 0;
}
