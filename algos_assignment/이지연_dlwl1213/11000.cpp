#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 수업 시간 목록
vector< pair<int, int> > class_time;

// 종료 시간 큐 (가장 작은 값이 우선순위가 되는 큐)
priority_queue< int, vector<int>, greater<int> > pq_less;

int greedy(int class_count){
    // 첫 번째 수업의 종료 시간을 pq 에 삽입
    pq_less.push(class_time[0].second);

    // 필요한 강의실 탐색
    for(int i=1; i<class_count; ++i){
        // i 번째 수업의 종료 시간을 pq 에 삽입
        pq_less.push(class_time[i].second);
        // top 의 종료 시간보다 i 번째 수업이 늦게 시작한다면, 같은 강의실에서 진행 가능
        if (pq_less.top() <= class_time[i].first){
            // 기존의 top 은 제거
            pq_less.pop();
        }
    }
    return pq_less.size();
}

int main(){

    // 수업 개수
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){

        // 수업 시작, 종료 시간
        int start_time, end_time;
        cin >> start_time >> end_time;

        // 수업 시간 저장
        class_time.push_back(make_pair(start_time, end_time));
    }

    sort(class_time.begin(), class_time.end());

    cout << greedy(n) << endl;
}
