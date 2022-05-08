#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> arr;
    for (int i = 0; i < N * N; i++)
    {
        int input;
        cin >> input;
        arr.push (input);
        if (arr.size() > N)
           arr.pop();
    }
    cout << arr.top() << "\n";
    return 0;
}
