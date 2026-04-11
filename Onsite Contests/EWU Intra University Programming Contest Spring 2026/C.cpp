#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	ll x, a, b; cin >> x >> a >> b;
	if(x == 0){
		cout << a - b;
	}
	else if(x == 1){
		cout << a + b;
	}
	else{
		ll p = a + b, q = a - b, z = a * b;
		ll ans = max(p, max(q, z));
		cout << ans;
	}
}
