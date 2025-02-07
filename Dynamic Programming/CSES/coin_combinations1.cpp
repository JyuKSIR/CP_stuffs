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
    vector<int> baal(x+1,0);
    baal[0]=1;
    for(int i=1; i<=x; i++){
		for(int j=0; j<n; j++){
			if(i>=c[j]) baal[i] = (baal[i]+baal[i-c[j]]) % mod;	
		}
	}
    cout << baal[x] << "\n";	

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
