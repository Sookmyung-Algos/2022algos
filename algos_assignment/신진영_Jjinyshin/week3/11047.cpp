#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K, min_num = 0;
    vector<int> coin_lst;
    cin >> N >> K;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        coin_lst.push_back(tmp);
    }
    for (int i = N - 1; i >= 0; i--) {
        min_num += K / coin_lst[i];
        K = K % coin_lst[i];
    }
    cout << min_num;
    return 0;
}
