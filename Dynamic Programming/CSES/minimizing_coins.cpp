#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int inf = 1e9;

void solve(){

    int n,x; cin >> n >> x;
	vector<int> c(n);
	for(int &a : c) cin >> a;
	vector<int> noobdp(x+1,inf);
	noobdp[0]=0;
	for(int i=0; i<n; i++){
		for(int j=c[i]; j<=x; j++){
			if(noobdp[j-c[i]]!=inf) noobdp[j]=min(noobdp[j],1+noobdp[j-c[i]]);
		}	
	}
	if(noobdp[x] == inf) cout << -1 << "\n";
	else cout << noobdp[x] << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
