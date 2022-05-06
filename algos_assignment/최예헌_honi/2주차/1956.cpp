#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);

	int v,e;
	int a,b,c;
	long long floyd [401][401]={0,};
	long long result=9876543210;

	cin>>v>>e;
	for (int i=1; i<=v; i++){
		for(int j=1; j<=v; j++){
			if (i==j) floyd[i][j]=0;
			else floyd[i][j]=9876543210;
		}
	}

	for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		floyd[a][b]=c;
	}

	for (int k=1;k<=v;k++){
		for (int i=1;i<=v; i++){
			for ( int j=1;j<=v; j++){
				if (floyd[i][j] >floyd[i][k]+floyd[k][j]){
					floyd[i][j]=floyd[i][k]+floyd[k][j];
				}
			}
		}
	}

	for (int i=1;i<=v;i++) {
		for (int j=1;j<=v;j++){
			if(i==j) continue;
			result= min(result,floyd[i][j]+floyd[j][i]);
		}
	}

	if (result==9876543210)
		cout<<-1;

	else
		cout<<result;

	return 0;

}
