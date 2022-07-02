#include <iostream>

typedef struct node {
    char left;
    char right;
} node;

node arr[27];

void pre(char root) {
    if (root == '.')
        return;

    printf("%c", root);
    pre(arr[root].left);
    pre(arr[root].right);
}

void in(char root) {
    if (root == '.')
        return;

    in(arr[root].left);
    printf("%c", root);
    in(arr[root].right);
}

void post(char root) {
    if (root == '.')
        return;

    post(arr[root].left);
    post(arr[root].right);
    printf("%c", root);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        char x, y, z;
        scanf("%c %c %c", &x, &y, &z);
        arr[x].left = y;
        arr[x].right = z;
    }

    pre('A');
    printf("\n");

    in('A');
    printf("\n");

    post('A');
    printf("\n");

    return 0;
}
