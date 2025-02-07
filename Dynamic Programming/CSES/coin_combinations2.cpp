#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int mod = 1e9+7;

void solve(){

    int n,x; cin >> n >> x;
	vector<int> c(n);
	for(int &a : c) cin >> a;
	vector<int> dhet(x+1,0);
	dhet[0]=1;
	for(int i=0; i<n; i++){
		for(int j=c[i]; j<=x; j++){
			dhet[j]=(dhet[j]+dhet[j-c[i]]) % mod;
		}	
	}
	cout << dhet[x] << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
