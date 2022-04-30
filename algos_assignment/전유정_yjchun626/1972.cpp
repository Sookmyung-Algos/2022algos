#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    while(cin>>s)  // "*" 입력될 때까지 무한 루프
    {
        if(s=="*") return 0;
        
        bool verify = true;  // 놀라운 문자열인지 판별하는 변수 verify
        for (int i = 1; i < s.length()-1; i++) 
        {            
            char a, b;
            for (int j = 0; j < s.length()-i; j++) 
            {
                    a = s[j];
                    b = s[j + i];
                    if (j + i == s.length() - 1) 
                    {
                        continue;
                    }
                for (int k = j+1; k < s.length() - i; k++) 
                {
                    // 똑같은 배열 한 개 이상 존재 시 놀라운 문자 아님
                    // false 입력후 반복문 탈출
                    if (a == s[k] && b == s[k + i]) 
                    {    
                        verify = false;
                        break;
                    }
                }
                if (!verify) 
                {
                    break;
                }
            }
            if (!verify) 
            {
                break;
            }
            
        }
                
        for (int i = 0; i < s.length(); i++)  // 문자 출력
        {
            cout << s[i];
        }
        
        if (verify)  // 판별 여부에 따라 다른 문구 출력
        {
            cout << " is surprising." << endl;
        }
        if (!verify) 
        {
            cout << " is NOT surprising." << endl;
        }       
    }
}
