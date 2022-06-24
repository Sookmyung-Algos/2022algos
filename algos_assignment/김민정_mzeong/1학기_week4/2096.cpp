#include <iostream>
#include <algorithm>
using namespace std;

int maxscore[3], minscore[3];

int main()
{
    int n; cin >> n;
    cin >> maxscore[0] >> maxscore[1] >> maxscore[2];
    minscore[0] = maxscore[0];
    minscore[1] = maxscore[1];
    minscore[2] = maxscore[2];
    for (int i = 1; i < n; i++) {
        int a, b, c, t1, t2, t3; 
        cin >> a >> b >> c;
        t1 = max(maxscore[0], maxscore[1]) + a;
        t2 = max({maxscore[0], maxscore[1], maxscore[2]}) + b;
        t3 = max(maxscore[1], maxscore[2]) + c;
        maxscore[0] = t1; maxscore[1] = t2; maxscore[2] = t3;
        
        t1 = min(minscore[0], minscore[1]) + a;
        t2 = min({minscore[0], minscore[1], minscore[2]}) + b;
        t3 = min(minscore[1], minscore[2]) + c;
        minscore[0] = t1; minscore[1] = t2; minscore[2] = t3;
    }
    cout << max({maxscore[0], maxscore[1], maxscore[2]}) << " ";
    cout << min({minscore[0], minscore[1], minscore[2]});
    return 0;
}
