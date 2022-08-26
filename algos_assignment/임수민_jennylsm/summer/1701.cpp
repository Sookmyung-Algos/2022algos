#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Fail(string Pattern) {
    vector<int> Pi(Pattern.length());
    for(int i=1, j=0; i<Pattern.length(); i++) {
        while(j>0 && Pattern[i] != Pattern[j]) j = Pi[j-1];
        if(Pattern[i] == Pattern[j]) Pi[i] = ++j;
    }
    return Pi;
}

int main() {
    string Str;
    cin >> Str;
    int Max = 0;
    for(int i=0; i<Str.length(); i++) {
        vector<int> Pi = Fail(Str.substr(i, Str.length()-i));
        for(int j=0; j<Str.length()-i; j++)
            if(Pi[j] > Max) Max = Pi[j];
    }
    cout << Max;
}
