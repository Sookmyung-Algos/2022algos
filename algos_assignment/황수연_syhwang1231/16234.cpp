#define MAX 50
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, L, R;  // N*N: 땅 크기, 두 나라 인구 차이가 L명 이상, R명 이하이면 국경선 open
int movingDays;  // 인구 이동이 일어나는 일 수
int populations[MAX][MAX];
bool visited[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};
bool hasMoved = true;  // true: 인구 이동 있었음, false: 인구 이동 없었음, true로 초기화

// 더 이상 국경 열 수 없을 때까지 while문 반복(전체 과정을 반복)
// while문 한 번 할 때마다 visited('하루'에 방문했는지에 대한 값) 초기화, 마지막에는 movingDays + 1
// 연합 찾기
  // 모든 칸을 돌기(for문)
    // !visited이면 각 칸마다 bfs함수 호출
        // bfs에서는 해당 나라가 국경 열 수 있는 조건에 맞으면->visited[] = true, 나라 수 +1, 인구 수 + [그 나라 인구 수], 나라 좌표를 따로 저장해두기
        // 원래 bfs 기능 수행(상하좌우 이동 하며 탐색)
        // queue가 empty 되어서 while문 끝나면 따로 저장해둔 나라 좌표들을 따라서 인구 수 갱신.
        // 나라 좌표 모아둔 저장소도 초기화.

void bfs(int r, int c){
    queue<pair<int, int>> q;  // bfs에서 사용할 큐
    queue<pair<int, int>> unions;  // 연합 나라들의 좌표 저장
    int totalPeople = 0;
    int nations = 0;
    
    // 매개 변수로 받은 나라에 대해 먼저 인구 수, 나라 개수 증가, visited 체크
    unions.push(make_pair(r,c));
    visited[r][c] = true;  // 해당 나라에 대해 visited
    totalPeople += populations[r][c];
    nations++;
    
    q.push(make_pair(r,c));
    
    // 연합 찾기
    while(!q.empty()){
        int curR = q.front().first;
        int curC = q.front().second;
        int curPop = populations[curR][curC];
        q.pop();
        
        for(int i=0; i<4; i++){
            int newR = curR+dr[i];
            int newC = curC+dc[i];  // 상하좌우 새 좌표
            
            if(newR<0 || newR>=N || newC<0 || newC>=N)  // 배열 범위 유효성 확인
                continue;
            
            int newPop = populations[newR][newC];
            if(abs(curPop-newPop)>=L && abs(curPop-newPop)<=R && !visited[newR][newC]){  // 인구 이동 가능 조건 확인
                hasMoved = true;  // 연합이 생겨야 인구 이동 가능하므로 
                visited[newR][newC] = true;  // 인구 이동 가능할 때 필요한 과정 수행
                nations++;
                totalPeople += populations[newR][newC];
                q.push(make_pair(newR, newC));
                unions.push(make_pair(newR, newC));
            }
        }
    }
    
    // 연합들의 인구 이동 수행
    int result = totalPeople/nations;  // 소숫점 버림
    while(!unions.empty()){
        int r = unions.front().first;
        int c = unions.front().second;
        unions.pop();
        
        populations[r][c] = result;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L >> R;
	for(int r=0;r<N;r++){
	    for(int c=0;c<N;c++){
	        cin >> populations[r][c];
	    }
	}
	
	while(hasMoved){  // 인구 이동이 있는 경우에만 반복
	    hasMoved = false;
	    memset(visited, false, sizeof(visited));
	    
	    for(int r=0; r<N; r++){
	        for(int c=0; c<N; c++){
	            if(!visited[r][c]){  // 아직 방문하지 않은 나라인 경우 bfs 호출
	                bfs(r, c);
	                //hasMoved = true;
	            }
	        }
	    }
	    
	    if(hasMoved)  // 인구 이동이 있었다면
	        movingDays++;
	}
	
	cout << movingDays;
	
	return 0;
}
