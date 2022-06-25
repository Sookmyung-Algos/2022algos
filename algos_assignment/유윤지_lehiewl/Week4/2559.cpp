#include<iostream>
using namespace std;
int main() {
	int tem[100001];
	int N, K;
	cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> tem[i];
    }

    int start = 0, sum = 0;
    int max = -1e9;

    for (int i = 0; i < N; ++i) {
        sum += tem[i];

        if (i >= K - 1) {
            if (sum > max) max = sum;
            sum -= tem[start++];
        }
    }
    cout << max;
}
