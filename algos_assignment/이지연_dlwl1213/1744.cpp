//백준1744 수묶기                                                            
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    vector<int> pos; //양수 저장
    vector<int> neg; //음수 저장
    vector<int> zero; //0 저장
    vector<int> ans; //출력 = ans벡터의 원소의 총합
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num > 0) {
            if (num == 1) {
                ans.push_back(num);
            }
            else {
                pos.push_back(num);
            }
        }
        else if (num < 0) {
            neg.push_back(num);
        }
        else { //num==0
            zero.push_back(num);
        }
    }
 
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
 
    /*양수*/
    int pSize = pos.size();
    if (pSize % 2 != 0) {
        ans.push_back(pos[0]);
    }
    for (int i = pSize - 1; i > 0; i-=2) {
        int big = pos[i];
        int small = pos[i - 1];
        int mul = big * small;
        ans.push_back(mul);
    }
 
    /*음수*/
    int nSize = neg.size();
    if (nSize % 2 != 0) {
        if (zero.size() > 0) {
            zero.pop_back();
        }
        else {
            ans.push_back(neg[nSize - 1]);
        }
    }
    for (int i = 0; i < nSize-1; i += 2) {
        int small = neg[i];
        int big = neg[i + 1];
        int mul = small * big;
        ans.push_back(mul);
    }
 
    /*출력 = ans벡터의 원소의 총합*/
    int sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i];
    }
    cout << sum;
    
 
    return 0;
}
