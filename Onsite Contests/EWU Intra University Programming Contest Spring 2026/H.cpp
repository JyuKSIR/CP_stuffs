#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	ll n, x; cin >> n >> x;
	ll a[n];
	x /= 2;
	map<ll, ll> mp;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	bool f = 0;
	for(int i = 0; i < n; i++){
		ll z = x - a[i];
		mp[a[i]]--;
		if(mp[z] > 0){
			f = 1;
			break;
		}
		mp[a[i]]++;
	}
	if(f) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while(tc--) solve();
}
