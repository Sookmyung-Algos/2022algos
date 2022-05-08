#include<iostream>

using namespace std;

int main() {
	char DNA[1000000];
	int P, S, A, C, G, T, start = 0, cnt = 0;
	cin >> S >> P;
	cin >> DNA;
	cin >> A >> C >> G >> T;

	while (start + P <= S) {
		int Ac = 0, Cc = 0, Gc = 0, Tc = 0;
		for (int i = start; i <= start + P - 1; i++) {
			if(DNA[i] == 'A')
				Ac++;
			else if(DNA[i]=='C')
				Cc++;
			else if(DNA[i]=='G')
				Gc++;
			else
				Tc++;
			}
		if ((Ac == A) && (Cc == C) && (Gc == G) && (Tc == T)) {
			cnt++;
		}
		start++;
	}
	printf("%d", cnt);
}
