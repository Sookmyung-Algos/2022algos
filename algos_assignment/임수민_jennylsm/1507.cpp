#include <iostream>
using namespace std;

int n;
int input_arr[21][21];
int answer_arr[21][21];
// 만약 출발지 -> 목적지 현재 최단길이기
// 다른데를 거쳐가는데보다 느리다?
// 직접 연결된 다리가 없고 돌아가는 길이 최단이라는겨

int main()
{
	int sum = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> input_arr[i][j];
			answer_arr[i][j] = input_arr[i][j];
		}

	//a 중간
	// b 시작 c 도착
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			for (int c = 0; c < n; c++)
			{
				if ((b == a) || (c == a))
					continue;
				if (input_arr[b][c] > input_arr[b][a] + input_arr[a][c])
				{
					cout << -1 << endl;
					return 0;
				}

				if (input_arr[b][c] == input_arr[b][a] + input_arr[a][c])
					answer_arr[b][c] = 0;

			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			sum += answer_arr[i][j];
		}

	cout << sum / 2 << endl;

	return 0;
}
