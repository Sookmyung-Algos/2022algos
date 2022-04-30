#include <iostream> 
#include <algorithm>
 
using namespace std;
 
typedef struct meeting {
    int start;
    int fin;
}meeting;
 
meeting* meeting_arr[100000];
int total_meeting = 0;
int now_num = 0 ;
 
bool cmp_EDGE(meeting* a, meeting* b) { return a->fin < b->fin; }
bool cmp_EDGE_2(meeting* a, meeting* b) { return a->start < b->start; }
 
int main() {
    int total_num = 0;
    cin >> total_num;
 
    for (int i = 0; i < total_num; i++) {
        int start, end;
        cin >> start >> end;
 
        meeting_arr[i] = (meeting*)malloc(sizeof(meeting));
        meeting_arr[i]->start = start;
        meeting_arr[i]->fin = end;
    }
 
    sort(meeting_arr, meeting_arr + total_num, cmp_EDGE);
 
    for (int i = 0; i < total_num; i++) {
        if (now_num <= meeting_arr[i]->start){
 
            int j = i+1; 
            while( (  j < total_num )  &&   ( meeting_arr[i]->fin == meeting_arr[j]->fin )  ){
                j++;
            }
            sort(meeting_arr+i, meeting_arr + j  , cmp_EDGE_2);
 
            now_num = meeting_arr[i]->fin;
            total_meeting++;
        }
    }
 
    cout << total_meeting;
    return 0;
}
