#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 10;

int min_ans, total_cnt;
int paper_cnt[5] = { 0,0,0,0,0 };
int board[MAX][MAX];

bool can_attach_paper(int x, int y, int size)
{
	register int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
			if (!board[x + i][y + j])
				return false;
	}
	return true;
}

void update_paper(int x, int y, int size, bool is_attach)
{
	register int i, j;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
				board[x + i][y + j] = is_attach;
}

void dfs(int x, int y, int attach_cnt)
{
	// 1. 1을 찾을 때까지 증가
	while (board[x][y] == 0)
	{
		if (++y >= MAX)
		{
			if (++x >= MAX)
			{
				min_ans = min(min_ans, attach_cnt);
				return;
			}
			y = 0;
		}
	}

	// 가지 치기
	if (min_ans <= attach_cnt)
		return;

	// 2. 모든 크기를 시도 (5,4,3,2,1)
	for (int s = 5; s > 0; --s)
	{
		// 범위 벗어남, 남은 종이 없음
		if (x + s > MAX || y + s > MAX || paper_cnt[s] == 5) continue;

		// 3. 색종이 부착 시도
		if (can_attach_paper(x, y, s))
		{
			// 4. 부착
			update_paper(x, y, s, 0);
			++paper_cnt[s]; 
			dfs(x, y, attach_cnt + 1); 

			// 5. 제거
			update_paper(x, y, s, 1);
			--paper_cnt[s];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	min_ans = 987654321;
	register int i, j;
	for (i = 0; i < MAX; ++i)
	{
		for (j = 0; j < MAX; ++j)
		{
			cin >> board[i][j];
			if (board[i][j]) ++total_cnt;
		}
	}
	if (total_cnt == MAX * MAX)
	{
		cout << 4; 
        return 0;
	}

	dfs(0, 0, 0);
	if (min_ans == 987654321) min_ans = -1;
	cout << min_ans;
	return 0;
}
