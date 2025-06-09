#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

void solve(){
    int n; cin >> n;
    vector<int> ar(n);
    for(auto &a : ar) cin >> a;

    vector<int> lis(n,1), lds(n,1);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(ar[i] > ar[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(ar[i] > ar[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int l = 2 * min(lis[i], lds[i]) - 1;
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
