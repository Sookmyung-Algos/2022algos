#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> adj[50];

//here에서 직접,간접 부하에게 뉴스를 전파할때 걸리는 최소시간
int Solve(int here)
{
	int ret = 0;

	vector<int> time; //here의 각 자식노드에서 직접,간접 부하에게 뉴스를 전파할때 걸리는 시간을 저장

	//here의 부하직원이 없을때
	if (adj[here].size() == 0)
		return 0;

	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		time.push_back(Solve(there));
	}

	//시간이 오래걸리는것부터 전파하기위해 내림차순으로 정렬한다(오름차순 정렬뒤 뒤집는다)
	sort(time.begin(), time.end());
	reverse(time.begin(), time.end());

	int cnt = 0;
	for (int i = 0; i < time.size(); i++)
	{
		cnt++; //직접부하중 몇번째로 전파하는지
		ret = max(ret, (time[i] + cnt)); //최댓값이 here에서 here의 모든 직접,간접 부하에게 뉴스를 전파할때 걸리는 시간이 된다
	}

	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int input;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input == -1)
			continue;

		adj[input].push_back(i);
	}

	cout << Solve(0);

	return 0;
}
