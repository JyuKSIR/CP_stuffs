#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const ll N = 1e5+5;
ll ar[N];
ll cost=0;

bool f(ll x,ll y,ll n){
	ll check[n];

	ll sum=0;
    for(ll i=0; i<n; i++){
	    check[i]=(ar[i]+(i+1)*x);	
	}
	sort(check,check+n);
	for(ll i=0; i<x;i++) sum+=check[i];
    if(sum<=y){
		cost=max(cost,sum);
	   	return 0;
	}
    else return 1;	
}

void solve(){

    ll n,s; cin >> n >> s;
    for(ll i=0; i<n; i++) cin >> ar[i];	
	ll l=0,r=n;
	while(l<=r){
		ll m = (l+r)/2;
	    if(f(m,s,n)) r = m - 1;
	    else l = m + 1;	
	}
	cout << r << " " << cost << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
