//
//  25401.cpp
//  icpc_prac_22
//
//  Created by 최예헌 on 2022/10/10.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int arr[505];
    vector <pair<int,int>> v;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int result = 600;
    for (int i=0;i<n-1;i++){

        for (int j=i+1; j<n;j++){
            int cnt=0;
            if ((arr[j]-arr[i])%(j-i) == 0){
                int d = (arr[j]-arr[i])/(j-i);
                
                for (int k=0;k<n;k++){
                    if (arr[k]-arr[i] != d*(k-i))
                        cnt++;
                }
                result = min(result,cnt);
            }
        }
        
    }
    if (result == 600)
        cout<<"0";
    else
        cout<<result;
}

