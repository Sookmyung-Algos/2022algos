#include <iostream>
#include <vector>

using namespace std;

// 포도주 목록
vector<int> Wine;

// 최대 포도주 양 목록
vector<int> D;

// 최대값 반환 함수
int max(int a, int b){
    return a > b ? a : b;
}

int dynamic(){

    // 최대 포도주 양 목록의 idx 는 4부터 시작
    for(int i=3; i<Wine.size(); ++i){

        // W_i 를 마셨을 경우와 W_i 를 마시지 않았을 경우를 비교해, 최대 포도주 양 추가
        D.push_back(max(max( D[i-3] + Wine[i-1] + Wine[i], D[i-2] + Wine[i]), D[i-1]));
    }

    // 최대 포도주 양 목록의 마지막 요소 반환
    return D[Wine.size()-1];

}

int main(){

    // 포도주 개수 입력
    int n;
    cin >> n;

    // 포도주 목록과 최대 포도주 양 목록의 초기 3개는 0 으로 초기화
    for (int i=0; i<3; ++i){
        Wine.push_back(0);
        D.push_back(0);
    }

    // 포도주 목록 입력
    int k;
    for (int i=0; i<n; ++i){
        cin >> k;
        Wine.push_back(k);
    }

    cout << dynamic() << endl;

}
