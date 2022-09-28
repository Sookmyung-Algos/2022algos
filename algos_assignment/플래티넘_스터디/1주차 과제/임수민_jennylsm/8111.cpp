#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;
int N;
int visited[20001] = {0};
pair<int, char> arr[20001];

void BFS(){
    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(1);        //첫 글자는 0 안 됨
    
    //가장 첫 루트 노드
    arr[1].first = -1;   //부모 노드 번호 표시 (부모가 -1이면 루트 노드인 것)
    arr[1].second = '1'; //N의 배수는 1부터 시작하므로

    visited[1] = 1;
    
    
    while(!que.empty()){
        
        int cur = que.front();
        que.pop();
        
        
        //자식 노드 2개, 가지치기, 0과 1을 붙일 수 있음
        int node[2];
        node[0] = (cur*10 + 0) % N;
        node[1] = (cur*10 + 1) % N;
        
        for(int i = 0; i<2; i++){
            if(visited[node[i]]==1) continue;
            
            arr[node[i]].first = cur;   //node[i]의 부모 노드는 cur
            arr[node[i]].second = i + '0';      // 현재 수에서 어떤 수를 덧붙였는지 저장, i는 0또는 1인 정수. 여기에 '0' 더해서 char 형으로 변환
            
            if(node[i]==0) return;      //N으로 나눈 나머지가 0이므로 N의 배수 찾은 것
            
            visited[node[i]] = 1;       //방문했음을 표시
            que.push(node[i]);
            
            
        }
        
        
    }
    
}

void printReverse(int parent){
    if(parent==-1) return;      //부모 노드가 -1이면 루트 노드
    
    printReverse(arr[parent].first);
    cout << arr[parent].second;
    
}


int main(){
    
    
    int T; cin >> T;
    
    for(int test_case = 1; test_case<=T; test_case++){
        
         cin >> N;
        if(N==1) {
            cout << 1 << endl;      //1의 배수는 1이므로 바로 출력
            continue;
        }
        
        BFS();
        printReverse(0);            //arr[0] 부터 거꾸로 타고 올라감. 0부터 시작하는 이유는 N의 배수가 되면서 나머지가 0이 됐고 이를 인덱스로 해서 저장했기 때문에
        cout << endl;
        
        
    }
    
    return 0;
}
