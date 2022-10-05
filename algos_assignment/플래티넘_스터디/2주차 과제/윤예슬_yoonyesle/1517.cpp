#include <iostream>
int a[1000001], temp[1000001];
long long sum;
void mSort(int s, int e){
	if(s<e){
                int m = s+e>>1;
                mSort(s,m);
                mSort(m+1,e);
                int *i = a+s, *j=a+1+m, *k=temp+s, *mid = a+m, *end = a+e;
                while(i<=mid && j<=end){
                        if(*i <= *j)
                                *k++ = *i++;
                        else{
                                *k++ = *j++;
                                sum += 1+(int)(mid-i);
                        }
                }
                while(i<=mid)
                        *k++ = *i++;
                while(j<=end)
                        *k++ = *j++;
                for(; s<=e; s++)
                        *(a+s) = *(temp+s);
        }
}
int main(void) {
	int n, i=0;
	scanf("%d", &n);
	for(; i<n; i++)
		scanf("%d", &a[i]);
	sum=0;
	mSort(0,n-1);
	printf("%lld", sum);
	return 0;
}
