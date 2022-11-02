#include <iostream>

#include <cmath>

using namespace std;

typedef long double ld;

ld n, d;

ld arr[1000002];

ld max1 = -INFINITY;

ld min1 = INFINITY;

ld max2 = -INFINITY;

ld min2 = INFINITY;

int main(){

    cin.tie(0); cout.tie(0);

    ios::sync_with_stdio(false);

    

    cin>>n>>d;

    for (int i=1; i<=n; i++){

        cin>>arr[i];

    }

    

    for (int i=1; i<=n; i++){

        ld temp1 = arr[i] - (i-1)*d;

        ld temp2 = arr[i] + (i-1)*d;

        

        if (max1 < temp1)

            max1 = temp1;

        if (min1 > temp1)

            min1 = temp1;

        

        if (max2 < temp2)

            max2 = temp2;

        if (min2 > temp2)

            min2 = temp2;

    }

    ld x1 = (max1 + min1)/2.0;

    ld x2 = (max2 + min2)/2.0;

    

    cout<<fixed;

    cout.precision(1);

    cout<<min( max(abs(max1 - x1), abs(min1 - x1)), max(abs(max2 - x2), abs(min2 - x2)));

}

