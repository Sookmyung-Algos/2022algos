#define MAX 1000000001
#include <iostream>
#include <cmath>
using namespace std;
long long *maxTree;
long long *minTree;
long long arr[100000];

int init(int node, int start, int end, bool maximum){
    if(start==end){
        if(maximum) return maxTree[node] = arr[start];
        else return minTree[node] = arr[start];
    }
    int mid = start + (end-start)/2;
    if(maximum) return maxTree[node] = max(init(2*node,start,mid,maximum), init(2*node+1,mid+1,end,maximum));
    return minTree[node] = min(init(2*node,start,mid,maximum), init(2*node+1,mid+1,end,maximum));
}

int findVal(int node, int start, int end, int left, int right, bool maximum){
    if(left>end || right < start){
        if(maximum) return -MAX;
        return MAX;
    }
    if(left<=start && end<=right){
        if(maximum) return maxTree[node];
        else return minTree[node];
    }
    int mid = start + (end-start)/2;
    if(maximum) return max(findVal(node*2,start,mid,left,right,maximum),findVal(node*2+1,mid+1,end,left,right,maximum));
    return min(findVal(node*2,start,mid,left,right,maximum),findVal(node*2+1,mid+1,end,left,right,maximum));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num,height,query,big,small,a,b;
    cin>>num>>query;
    height = ceil(log2(num));
    minTree = new long long[1<<(height+1)];
    maxTree = new long long[1<<(height+1)];
    for(int i=0;i<(1<<(height+1));i++)
        minTree[i]=MAX;
    for(int i=0;i<num;i++)
        cin>>arr[i];
    init(1,0,num-1,true);
    init(1,0,num-1,false);
    
    for(int i=0;i<query;i++){
        cin>>a>>b;
        big = a>b ? a : b;
        small = a>b ? b : a;
        cout << findVal(1,0,num-1,small-1,big-1,false)<<" "<<findVal(1,0,num-1,small-1,big-1,true)<<'\n';
    }
    return 0;
}
