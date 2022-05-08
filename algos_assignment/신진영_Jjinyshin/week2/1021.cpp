#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

void moveRight() {
    dq.push_front(dq.back());
    dq.pop_back();
}

void moveLeft() {
    dq.push_back(dq.front());
    dq.pop_front();
}

int main()
{
    int N, M, target, idx, cnt = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    for (int i = 0; i < M; i++) {
        cin >> target;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == target) {
                idx = j;
                break;
            }
        }
        if (idx > dq.size() - idx) {
            while (dq.front() != target) {
                moveRight();
                cnt++;
            }
        }
        else {
            while (dq.front() != target) {
                moveLeft();
                cnt++;
            }
        }
        dq.pop_front();
    }

    cout << cnt;
    
    return 0;
}
