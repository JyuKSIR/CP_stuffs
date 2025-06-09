#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){

    int n; cin >> n;
    int ar[n],dp1[n],dp2[n];
    for(auto &a : ar) cin >> a;

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));

    function<int(int)> lis = [&](int i){
        if(dp1[i] != -1) return dp1[i];
        int ct = 1;
        for(int j = 0; j<i; j++){
            if(ar[i]>ar[j]){
                ct = max(ct, lis(j)+1);
            }
        }
        return dp1[i] = ct;
    };

    function<int(int)> lds = [&](int i) {
        if (dp2[i] != -1) return dp2[i];
        int ct = 1;
        for (int j = i + 1; j < n; j++) {
            if (ar[i] > ar[j]) {
                ct = max(ct, lds(j) + 1);
            }
        }
        return dp2[i] = ct;
    };

    int ans = 0;

    for(int i=0; i<n; i++){
        int lois = lis(i);
        int lods = lds(i);
        int l = 2 * min(lois,lods) - 1;
        ans = max(ans, l);
    }

    cout << ans << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i = 1; cin >> t;

    while(t--){
        cout << "Case " << i << ": ";
        solve();
        i++;
    }

  return 0;
}
