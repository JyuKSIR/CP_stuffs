
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const ll N = 1e5+5;
ll ar[N];
ll n,k;
vector<pair<bool,ll>> v;

bool check(ll d){
	ll cows=k;
	ll putcow=-1;
	for(ll i=0; i<n; i++){
		if(ar[i]-putcow>=d || putcow == -1){
			putcow = ar[i];
			cows--;
		}
		if(cows == 0) break;
	}
	return (cows == 0);
}

void solve(){
	memset(ar,0,sizeof(ar));
	cin >> n >> k;
	for(ll i=0; i<n; i++) cin >> ar[i];
	sort(ar,ar+n);
	ll lo=0,hi=1e9;
	while(hi-lo>1){
		ll mid = (hi+lo)/2;
		dbg(lo);
		dbg(hi);
		dbg(mid);
	    if(check(mid)) {
			lo=mid;
			dbg(lo);
			v.push_back({1,mid});
		}
	    else{
		    hi = mid-1;
			dbg(hi);
			v.push_back({0,mid});
		}	
	}
	dbg(lo);
	dbg(hi);
	if(check(hi)) cout << "hi " <<hi << "\n";
	else cout << lo << "\n";
	for(auto x : v) cout << x.first << " " << x.second << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    while(t--){
       solve();
    }

  return 0;
}
