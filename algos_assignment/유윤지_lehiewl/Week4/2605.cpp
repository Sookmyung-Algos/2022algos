#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    int n, x;
    vector<int> light;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        light.insert(light.begin() + x, i); 
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << light[i];
    }

}
