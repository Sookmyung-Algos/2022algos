#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

int main() {
    char ar[51];
    scanf("%s", ar);

    int oper = 0, j = 1;
    int index[50];
    char oar[50];

    for (int i = 0; i < 51; i++) {
        if (ar[i] == '+' || ar[i] == '-') {
            oper++;
            index[j] = i;
            oar[j] = ar[i];
            j++;
        }
    }

    int* number = new int[oper+1];
    number[0] = atoi(&ar[0]);
    for (int i = 1; i < j; i++) {
        number[i] = atoi(&ar[index[i]+1]);
    }

    int sum = number[0];
    int tmp = 0;
    oar[0] = ' ';

    for (int i = 1; i < j; i++) {
        if (oar[i] == '-') {
            for (int k = i; k < j; k++) sum -= number[k];
            break;
        }
        else sum += number[i];
    }

    printf("%d", sum);
}
