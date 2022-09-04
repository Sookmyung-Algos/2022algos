#include <iostream>
#include <vector>

using namespace std;

int parents[51];
vector <int> know;
vector <vector<int>> party(50);

int Find(int x) {
	if (parents[x] == x) return x; //x의 부모가 x와 같다면 단일 노드
	return x = Find(parents[x]); //그렇지 않다면 루트 노드를 찾을 때까지 재귀적으로 탐색
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parents[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, K;

	cin >> N >> M >> K; //K = 진실을 아는 사람의 수

	while (K--) {
		int truth; //진실을 아는 사람의 번호
		cin >> truth;
		know.push_back(truth); //진실을 아는 사람의 번호를 know 벡터에 push
	}

	for (int i = 1; i <= N; i++) { //모든 노드가 자기 자신을 가리키도록 초기화
		parents[i] = i;
	}

	for (int i = 0; i < M; i++) { //파티의 수만큼 반복
		int num, prev, member;
		cin >> num; //파티에 오는 사람 수


		for (int j = 0; j < num; j++) {
			if (j < 1) {
				cin >> member;
			}
			else {
				prev = member;
				cin >> member;
				Union(prev, member);
			}
			party[i].push_back(member);
		}
	}

	for (auto& list : party) {
		bool flag = false;
		for (auto& person : list) {
			if (flag) break;
			for (auto& truth : know) {
				if (Find(person) == Find(truth)) {
					flag = true;
					break;
				}
			}
		}
		if (flag) M--;
	}
	cout << M;

	return 0;
}
