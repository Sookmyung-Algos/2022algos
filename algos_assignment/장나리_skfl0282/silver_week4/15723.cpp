#include <iostream>
#include <string>
using namespace std;

const int MAX = 26;
const int INF = 9999999;
int n, m;
int map[MAX][MAX];
char ans[MAX];

void floyd() {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> n;
    cin.ignore();

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        int pre = input[0] - 'a';
        int nxt = input[input.length() - 1] - 'a';
        map[pre][nxt] = 1;
    }

    floyd();

    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++) {
        string quiz;
        getline(cin, quiz);
        int pre = quiz[0] - 'a';
        int nxt = quiz[quiz.length() - 1] - 'a';
        if (map[pre][nxt] != INF) {
            ans[i] = 'T';
        }
        else {
            ans[i] = 'F';
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
