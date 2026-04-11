#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	ll a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	ll s = a + b + c + d + e;
	if(80 - s <= 25){
		cout << 80 - s;
	}
	else cout << "Impossible, Good Luck Next Time";
}
