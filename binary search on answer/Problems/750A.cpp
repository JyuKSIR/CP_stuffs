#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

bool f(int x, int k){
	k=240-k;
    if(((x*(x+1))/2)*5<=k) return 0;
	else return 1;
}

void solve(){

    int n,k; cin >> n >> k;
	int l=0,r=n;
	while(l<=r){
		int mid = (r+l)/2;
		if(f(mid,k)) r = mid-1;
	    else l = mid+1;	
	}
	cout << r << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

       solve();

  return 0;
}
