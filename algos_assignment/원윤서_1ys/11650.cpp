#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct position
{
	int x, y;
};

bool compare(position now, position last)
{
	if (now.x > last.x)
    return false;
	if (now.x == last.x && now.y > last.y)
    return false;
	else
    return true;
}

int main()
{
	int N;
	scanf("%d", &N);
	struct position arr[100001];

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + N, compare);

	for (int i = 0; i <N; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}
