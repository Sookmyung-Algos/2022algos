#include <iostream> 
#include <algorithm> 
#define MAX 1000000
using namespace std;

int N;
int tree[MAX];
int treemin[MAX];

bool cmp(int a, int b) { return a > b; }

int main() {
	cin >> N; 
	for (int i = 0; i < N; i++) 
		cin >> tree[i]; 
	
	sort(tree, tree + N, cmp); // 내림차순
							   
	for (int i = 0; i < N; i++) 
		treemin[i] = (i + 1) + tree[i]; 

	sort(treemin, treemin + N, cmp); 
	
	cout << treemin[0] + 1; 
	return 0; 
}
