#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N, M, cash[MAX];

bool func(int mid) {

    int num = 1, sum = mid, i;

    for (i = 0; i < N; i++)

    {
        if (mid < cash[i])
            return false;



        if (sum - cash[i] < 0){
            sum = mid;
            num++;
        }

        sum -= cash[i];
    }

    return M >= num;
}



int main(void)

{
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cin >> N >> M;

    int sum = 0, i;

    for (i = 0; i < N; i++){
        cin >> cash[i];
        sum += cash[i];
    }

    int low = 1, high = sum, result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (func(mid)) {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << result << "\n";

    return 0;
}
