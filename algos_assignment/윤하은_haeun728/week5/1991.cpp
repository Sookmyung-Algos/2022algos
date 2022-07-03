#include <iostream>
#include <vector>

using namespace std;

struct node {
	char me;
	char lc;
	char rc;
};

vector<node> v;

void preorder(node n) { //전위순회
	cout << n.me;
	if(n.lc!='.') preorder(v[n.lc - 65]);
	if (n.rc != '.') preorder(v[n.rc - 65]);
}

void inorder(node n) { //중위순회
	if (n.lc != '.') inorder(v[n.lc - 65]);
	cout << n.me;
	if (n.rc != '.') inorder(v[n.rc - 65]);
}

void postorder(node n) { //후위순회
	if (n.lc != '.') postorder(v[n.lc - 65]);
	if (n.rc != '.') postorder(v[n.rc - 65]);
	cout << n.me;
}

int main()
{
	int n;
	cin >> n;
	v.resize(n);

	for (int i = 0;i < n;i++) {
		char c, left, right;
		cin >> c >> left >> right;
		v[c - 65].me = c;
		v[c - 65].lc = left;
		v[c - 65].rc = right;
	}

	preorder(v[0]);
	cout << endl;
	inorder(v[0]);
	cout << endl;
	postorder(v[0]);

	return 0;
}
