#include <string>
#include <vector>
#include <limits.h> 
using namespace std;

int main()
{
    int N, K, B;
    scanf("%d %d %d", &N, &K, &B);
    vector<int> TraifficLights(N, 0);

    int temp = 0;
    for (int b = 0; b < B; b++) {
        scanf("%d", &temp);
        TraifficLights[temp - 1] = 1;
    }

    int ans = INT_MAX;

    for (int i = 0; i < N - K + 1; i++) {
        temp = 0;
        for (int j = i; j < i + K; j++) {
            temp += TraifficLights[j];
        }
        ans = ans < temp ? ans : temp;
    }
    printf("%d", ans);
    return 0;
}
