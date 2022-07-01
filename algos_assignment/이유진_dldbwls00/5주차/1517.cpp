#include <iostream>
using namespace std;

const int MAX = 500000;

int arr[MAX], arr2[MAX];
int n;
long long func(int start, int end){
    if (start == end)   return 0;

    int mid = (start + end) / 2;
    long long result = func(start, mid) + func(mid + 1, end);
    int i = start;
    int j = mid + 1;
    int idx = 0;

    while (i <= mid || j <= end){

       
        //순서대로 잘 있는 경우
        if (i <= mid && (j > end || arr[i] <= arr[j]))  arr2[idx++] = arr[i++];
        else{
            result += (mid - i + 1) * 1LL; //왼쪽 개수 파악
            arr2[idx++] = arr[j++];
        }
    }

    for (int k = start; k <= end; k++)  arr[k] = arr2[k - start]; //배열 업데이트

    return result;
}

int main(void){
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    long long result = func(0, n - 1);
    cout << result << "\n";

    return 0;
}
