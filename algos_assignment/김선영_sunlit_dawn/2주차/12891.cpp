#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char l[1000001];
char num[4];

int count(int a);

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
    {    
        num[count(i)]++;
        if (num[0] >= a && num[1] >= c && num[2] >= g && num[3] >= t)
          r++;
    }
    for (int i = 0; i<(s - p +1);i++)
    {
        num[count(i)]--;
        num[count(i+p-1)]++;
        if (num[0] >= a && num[1] >= c && num[2] >= g && num[3] >= t)
          r++;
    }
    
    cout << r;
}

int count(int a)
{
    if (l[a] == 'A')
        return 0;
    else if (l[a] == 'C')
        return 1;
    else if (l[a] == 'G')
        return 2;
    else if (l[a] == 'T')
        return 3;
      
}
