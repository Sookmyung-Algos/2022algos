#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);      

        while (1)
        {               
                 string s;
                 cin >> s;
            
                 if (s == "*")
                         break;
 
                 int len = 1;
                 bool surprising = true;

                 while (len < s.length())
                 {                        
                         vector<string> word;
                         for (int i = 0; i < s.length(); i++)
                         {
                                 if (i + len >= s.length())
                                          break;
                                 string temp = "";
                                 temp += s[i];
                                 temp += s[i + len];
                                 word.push_back(temp);
                         }
                         for(int i=0; i<word.size(); i++)
                                 for(int j=i+1; j<word.size(); j++)
                                          if (word[i] == word[j])
                                          {
                                                  surprising = false;
                                                  break;
                                          }
                         if (!surprising)
                                 break;
                         len++;
                 }
                 if (surprising)
                         cout << s << " is surprising.\n";
                 else
                         cout << s << " is NOT surprising.\n";
        }
        return 0;
}
