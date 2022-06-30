#include <iostream>
#include <algorithm>
#include <vector>
const int MAX = 100001;
using namespace std;

bool visit[MAX];
vector<vector <int>> node;

int getint(){
    int a;
    cin >> a;
    return a;
}

int main(){
    int v;
    cin >> v;
    
    for (int i = 0; i<v; i++){
        int temp;
        cin >> temp;
        node.push_back(temp);

        int b[2], j = 0;
        while(int c = getint() != -1){
            b[j] = c;
            j++;
            if (j == 2){
                node[i].push_back(b[0]);
                node[i][0].push_back(b[1]);
                b[0] = 0, b[1] = 0;
            }
             
        }
    }
}
