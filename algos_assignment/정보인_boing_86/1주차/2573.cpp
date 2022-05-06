#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
int years = 0;
int map[301][301] = {0, };
int tmp[301][301] = {0, };
bool visited[301][301] = {false,};
int prow[4] = { -1, 0, 1, 0 };
int pcol[4] = { 0, 1, 0, -1 };
queue <pair<int, int>> q;


void bfs(int x, int y){
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
		int cy = q.front().second;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = cx + prow[i];
			int ny = cy + pcol[i];

			if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]!=0){
				if(!visited[nx][ny]){
                	q.push({nx, ny});
                	visited[nx][ny] = true;
            	}
			}
        }
    }
}

void oneyearlater(){

    for (int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
			int sides = 0;
			if(map[i][j] != 0){
				for(int k = 0; k<4;k++){
					int nx = i + prow[k];
					int ny = j + pcol[k];

					if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny] == 0){
						sides++;
					}
					tmp[i][j] = sides;
				}
			}
        }
	}

	for (int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
			int height = map[i][j] - tmp[i][j];
			if(height > 0){
				map[i][j] = height;
			}
			else{
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin>>n>>m;

	for (int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>map[i][j];
		}
	}

    while(true){
		int cnt = 0;
        for (int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
				if(!visited[i][j] && map[i][j]!=0){
					bfs(i, j);
					cnt++;
				}
            }
		}
		if(cnt == 0){
			cout<<0;
			return 0;
		}

		if(cnt >= 2){
			cout<<years;
			return 0;
		}

		years++;
		oneyearlater();
		memset(visited, false, sizeof(visited));
		memset(tmp, 0, sizeof(tmp));
    }

}
