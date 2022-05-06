#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
const int MAX = 123456;
int map[27][27] = {0, };

int main(){
    cin>>n;
    cin.ignore();

    for(int i = 0; i<27; i++){
        for(int j = 0; j<27; j++){
            if(i != j){
                map[i][j] = MAX;
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        string line;
        getline(cin, line);
        int p = line[0] - 'a';
        int q = line[line.length()-1] - 'a';
        map[p][q] = 1;
    }

    for(int k = 0; k<27; k++){
        for(int i = 0; i<27; i++){
            for(int j = 0; j<27; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    cin>>m;
    cin.ignore();

    for(int i = 0; i<m; i++){
        string prop;
        getline(cin, prop);
        int p1 = prop[0] - 'a';
        int q1 = prop[prop.length()-1] - 'a';

        if(map[p1][q1] != MAX){
            cout<< 'T'<<"\n";
        }
        else{
            cout<< 'F'<<"\n";
        }
    }


}
