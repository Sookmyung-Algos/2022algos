#include <iostream>

using namespace std; 

int s, p;
int a, c, g, t;
int result=0; 
int dnacount[4] = { 0, }; 
char dna[1000001] = { 0, }; 

int main() {

    cin >> s >> p; 
    
    for (int i = 0; i < s; i++) {
        cin >> dna[i]; 
    }
    cin >> a >> c >> g >> t; 

    for (int i = 0; i < p; i++) {
        char temp; 
        temp = dna[i];
        if (temp == 'A') dnacount[0]++;
        else if (temp == 'C') dnacount[1]++;
        else if (temp == 'G') dnacount[2]++;
        else if (temp == 'T') dnacount[3]++; 
    }

    for (int i = 0; i < s - p + 1;) {
        if (dnacount[0] >= a && dnacount[1] >= c && dnacount[2] >= g && dnacount[3] >= t) result++; 
        char temp;
        temp = dna[i];
        if (temp == 'A') dnacount[0]--;
        else if (temp == 'C') dnacount[1]--;
        else if (temp == 'G') dnacount[2]--;
        else if (temp == 'T') dnacount[3]--;
        i++; 
        
        temp = dna[i + p - 1]; 
        if (temp == 'A') dnacount[0]++;
        else if (temp == 'C') dnacount[1]++;
        else if (temp == 'G') dnacount[2]++;
        else if (temp == 'T') dnacount[3]++;
    }
    cout << result; 
}
