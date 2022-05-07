#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char l[1000001];
char num[4];

int main()
{
    int s, p; 
    string d;
    int a, c, g, t;
  
    cin >> s >> p;
    cin >> d;
    cin >> a >> c >> g >> t;

    for (int i = 0; i<s; i++)
      l[i] = d[i];
  
    int r = 0;

    for (int i = 0; i < p; i++)
    {    if (l[i] == 'A')
            num[0]++;
        else if (l[i] == 'C')
            num[1]++;
        else if (l[i] == 'G')
            num[2]++;
        else if (l[i] == 'T')
            num[3]++;
        if (num[0] >= a && num[1] >= c && num[2] >= g && num[3] >= t)
          r++;
    }
    for (int i = (p-1); i<s; i++)
    {
        if (l[i+1] == 'A')
            num[0]++;
        else if (l[i+1] == 'C')
            num[1]++;
        else if (l[i+1] == 'G')
            num[2]++;
        else if (l[i+1] == 'T')
            num[3]++;
      
        if (l[i-1] == 'A')
            num[0]--;
        else if (l[i-1] == 'C')
            num[1]--;
        else if (l[i-1] == 'G')
            num[2]--;
        else if (l[i-1] == 'T')
            num[3]--;

        if (num[0] >= a && num[1] >= c && num[2] >= g && num[3] >= t)
          r++;
    }
    
    cout << r;
}
