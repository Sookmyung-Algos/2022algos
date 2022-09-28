#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
#define mod 1000000

//두개의 2*2행렬을 곱하는 함수
vector<ll> Matrix_Multiply(vector<ll> a, vector<ll> b){
	vector<ll> c(4,0);
	c[0] = (a[0]*b[0]+a[1]*b[2])%mod;
	c[1] = (a[0]*b[1]+a[1]*b[3])%mod;
	c[2] = (a[2]*b[0]+a[3]*b[2])%mod;
	c[3] = (a[2]*b[1]+a[3]*b[3])%mod;
	return c;
}

int main() {
	//iostream과 stdio 버퍼 동기화시켜서 입력 빨리받아오자
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//==============================================
	ll n;
	cin>>n;
	//먼저 n을 이진수로 변환하여 vector binary_n에 저장
	vector<int> binary_n;
	ll nn = n-1; //1000은 999번 곱한결과이다.
	while(nn>1){
		ll one_bit = nn%2;
		binary_n.push_back(one_bit);
		nn = nn/2;
	}
	binary_n.push_back(1);
	
	//a^i을 vector<vector<int>> a에 저장
	vector<vector<ll>> a;
	vector<ll> temp(4,0);
	temp[0] = 1; temp[1] = 1;
	temp[2] = 1; temp[3] = 0;
	a.push_back(temp);
	for(int i = 1; i<70; i++){
		temp = Matrix_Multiply(a[i-1], a[i-1]);
		a.push_back(temp);
	}
	
	//binary_n에서 1인 값이 x라고 할때, a[x]들을 모두 곱하자. 1000000으로 나눈 나머지 vector answer에 저장
	vector<ll> answer(4,0);
	answer[0] = 1; answer[3] = 1;
	for(int x = 0; x<binary_n.size(); x++){
		if(binary_n[x]==1){
			answer = Matrix_Multiply(a[x], answer);
		}
	}
	
	//모두 곱한 결과가 answer에 담겼다고 하면 answer[0]가 정답
	cout<<answer[0];
	
	return 0;
}
