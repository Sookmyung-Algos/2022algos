#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;

int m,n,w,h;
int days, pers;

priority_queue<tii, vector<tii>> pq;     // {남은 일의 수, 시작 가능 날짜, 번호}
queue <tii> q;                           // 각 날짜에 일을 할 수 있는지 확인한 사람들
int dayCnt[2002]={0,};

vector <int> result[2002];

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>m>>n>>w>>h;
    for (int i=1; i<=m; i++){
        cin>>days;
        pq.push({days, 1, i});
    }
    
    for (int i=1; i<=n; i++){
        cin>>dayCnt[i];
    }
    
    for (int i=1; i<=n; i++){
        
        while (true){
            // 종료 조건
            if (pq.empty())
                break;
            
            if (dayCnt[i] == 0)
                break;
            
            int workDays = get<0>(pq.top());        // 남은 일수
            int startDay = get<1>(pq.top());        // 시작 가능 날짜
            int perNum = get<2>(pq.top());          // 번호
            pq.pop();
            
            if (workDays <= 0)
                continue;
            
            if (startDay <= i){         // 일을 시작할 수 있는 날짜
                
                if (workDays - w >= 0){
                    q.push({workDays-w, i+w+h, perNum});
                    
                    for (int k=0; k<w; k++){
                        dayCnt[i+k]--;
                        if (dayCnt[i+k] < 0){
                            cout<<"-1";
                            return 0;
                        }
                    }
                    result[perNum].push_back(i);
                }
            }
            
            else{
                q.push({workDays, startDay, perNum});
            }
        }
        
        if (dayCnt[i] != 0){
            cout<<"-1";
            return 0;
        }
        
        while (!q.empty()){
            pq.push({get<0>(q.front()), get<1>(q.front()), get<2>(q.front())});
            q.pop();
        }
    }
    
    cout<<"1\n";
    for (int i=1;i<=m;i++){
        for (int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
    }
    
    return 0;
}
