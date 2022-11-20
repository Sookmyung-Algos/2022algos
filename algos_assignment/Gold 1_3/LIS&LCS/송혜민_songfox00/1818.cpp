#include<iostream>
#include<algorithm>

using namespace std;

int n ,arr[200001], LIS[200001];;

int binary_search(int left, int right, int target){
    int mid;
    
    while(left<right){
        mid=(left+right)/2;
        
        if(LIS[mid]<target)
            left=mid+1;
        else
            right=mid;
    }
    
    return right;
}

int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    LIS[0]=arr[0];
    
    int j=0;
    for(int i=1;i<n;i++){
        if(LIS[j]<arr[i])
            LIS[++j]=arr[i];
        else{
            int idx=binary_search(0, j, arr[i]);
            LIS[idx]=arr[i];
        }
    }
    
    cout<<n-(j+1);
    return 0;
}
