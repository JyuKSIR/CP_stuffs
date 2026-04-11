#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	int n, k; cin >> n >> k;
	if(k > n) cout << "NO\n";
	else cout << "YES\n";
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll tc = 1;
	cin >> tc;
	while(tc--) solve();
}
