// 미완
#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int s, p, a, c, g, t;  // s: dna 문자열 길이 / p: 부분 문자열 길이
char dna[1000005] = { 0, };  // dna 문자열 저장
int acgt[4] = { 0, };  // a, c, g, t의 개수 - 인덱스 순서로 0, 1, 2, 3
int ans = 0;  // 만들 수 있는 비밀번호의 수

int main() 
{
    cin >> s >> p;  // 1. s, p 입력 받음
    
    for (int i = 0; i < s; i++)  // 문자열 길이 만큼 반복
    {
        cin >> dna[i];  // 2. dna 문자열 입력
    }
    
    cin >> a >> c >> g >> t;  // a, c, g, t의 최소 필요 개수 입력
    
    for (int i=0; i<p; i++)  // 부분 문자열 길이 만큼 반복
    {
        char t;  // 문자 임시 저장 위한 변수 t
        t = dna[i];
        
        if (t == 'A') 
            acgt[0]+=1;  // a 수 증가 - 인덱스 0...
        else if (t == 'C') 
            acgt[1]+=1;
        else if (t == 'G') 
            acgt[2]+=1;
        else if (t == 'T') 
            acgt[3]+=1; 
    }

    for (int i=0; i < s-p+1;)  // (전체 문자열 길이 - 부분 문자열)만큼 반복
    {
        if (acgt[0] >= a && acgt[1] >= c && acgt[2] >= g && acgt[3] >= t) 
            ans+=1;  
        // 모든 조건 충족할 시 결과값 증가
        
        char t;
        t = dna[i];
      
        if (t == 'A') 
            acgt[0]-=1;
        else if (t == 'C') 
            acgt[1]-=1;
        else if (t == 'G') 
            acgt[2]-=1;
        else if (t == 'T') 
            acgt[3]-=1;    
    }
    cout << ans;  // 결과 출력
}
