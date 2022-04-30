#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char A[51] = "", B[51] = "";
	int i, j, min, cnt, res;

	scanf("%s %s", &A, &B);

	min = strlen(B);

	for (i = 0; i <= strlen(B) - strlen(A); i++) {
		cnt = 0;
		res = 0;

		for (j = i; j < i + strlen(A); j++) {
			if (A[cnt] != B[j]) {
				res++;
			}

			cnt++;
		}
		if (min > res) {
			min = res;
		}
	}

	printf("%d", min);

	return 0;
}
