#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, cnt =0;
int xDir[4]={0, 0, -1, 1}, yDir[4]={1, -1, 0, 0};
queue<pair<int, int>> q;

int main() {
    cin>> n >> m;

    int maze[n][m];
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            maze[i][j] = str[j] - 48;
        }
    }
    
    q.push(make_pair(0,0));
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xPos = p.first + xDir[i], yPos = p.second + yDir[i];
            if (xPos < 0 || xPos >= m || yPos < 0 || yPos >= n) continue;
            if (maze[yPos][xPos] == 1){
                if (yPos == n - 1 && xPos == m - 1 && maze[yPos][xPos] != 1){
                    if (maze[p.second][p.first] + 1 < maze[yPos][xPos]) maze[yPos][xPos] = maze[p.second][p.first] + 1;
                }
                else{
                    maze[yPos][xPos] = maze[p.second][p.first] + 1;
                    q.push(make_pair(xPos,yPos));
                }
            }
        }   
    }
    cout << maze[n-1][m-1];

}
