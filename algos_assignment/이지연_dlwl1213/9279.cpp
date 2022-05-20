#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 1048576;
typedef long long ll;

int N, M, K;

class segmentTree
{
public:
	int Root, Begin, Size;
	vector<ll> node, lazy;

	segmentTree() : segmentTree(2000000) {}
	segmentTree(int ms) : Root(1), Begin(ms), Size(ms) {
		node.assign(ms * 2, 0);
		lazy.assign(ms * 2, 0);
	}

	void insert(int index, int num) { node[Begin + index - 1] = num; }

	void construct() 
	{
		for (int i = Begin - 1; i > 0; i--)
			node[i] = node[i * 2] + node[(i * 2) + 1];
	}

	void propagate(int index, ll currL, ll currR) 
	{
		if (lazy[index] != 0)
		{
			if (index < Begin)  // not Leaf
			{
				lazy[index * 2] += lazy[index];
				lazy[(index * 2) + 1] += lazy[index];
			}
			node[index] += (lazy[index] * (currR - currL + 1));
			lazy[index] = 0;
		}
	}

	void segmentAdd(int obtL, int obtR, int num) { segmentAdd(obtL, obtR, num, 1, 1, Size); }
	void segmentAdd(int obtL, int obtR, int num, int index, int currL, int currR)
	{
		propagate(index, currL, currR); // 이전에 미뤘던 lazy가 있을 수 있다.

		if (currR < obtL || obtR < currL) return;
		if (obtL <= currL && currR <= obtR)   // 현재 구간이 목적 구간에 포함되면 
		{
			lazy[index] += num;
			propagate(index, currL, currR);
			return;
		}

		int mid = (currL + currR) / 2;
		segmentAdd(obtL, obtR, num, index * 2, currL, mid);
		segmentAdd(obtL, obtR, num, (index * 2) + 1, mid + 1, currR);
		node[index] = node[index * 2] + node[(index * 2) + 1];
	}

	ll sum(int obtL, int obtR) { return sum(obtL, obtR, 1, 1, Size); }
	ll sum(int obtL, int obtR, int index, int currL, int currR)
	{
		propagate(index, currL, currR); // 이전에 미뤘던 lazy가 있을 수 있다.

		if (currR < obtL || obtR < currL) return 0;
		if (obtL <= currL && currR <= obtR) return node[index];

		int mid = (currL + currR) / 2;
		return sum(obtL, obtR, index * 2, currL, mid) 
			+ sum(obtL, obtR, (index * 2) + 1, mid + 1, currR);
	}
};

int main()
{
	segmentTree st(maxSize);

	scanf("%d %d %d", &N, &M, &K);
	{
		int a, b, c, d, temp;
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &temp);
			st.insert(i, temp);
		}

		st.construct();

		for (int i = 0; i < M + K; i++)
		{
			scanf("%d", &a);

			if (a == 1)
			{
				scanf("%d %d %d", &b, &c, &d);
				st.segmentAdd(b, c, d);
			}
			else
			{
				scanf("%d %d", &b, &c);
				printf("%lld\n", st.sum(b, c));
			}
		}
	}

	return 0;
}
