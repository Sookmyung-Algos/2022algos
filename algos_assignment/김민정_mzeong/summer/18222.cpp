#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
	if(x == 1) return 0;
	ll i = 1;
	while (i + i < x) i += i;
	return !f(x - i);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
	ll k; cin >> k;
	cout << f(k);
	return 0;
}
