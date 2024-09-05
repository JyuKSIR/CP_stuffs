// ref. --> https://www.youtube.com/watch?v=nZe7P674xZo&t=1229s


#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 1005;

int store[N][N];
int pref_sum[N][N];

void solve(){

    int n,m;
    cin >> n >> m;
    // vector<vector<int>> store(n+1,vector<int> (m+1));
    // vector<vector<long long>> pref_sum(n+1,vector<long long> (m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> store[i][j];
            pref_sum[i][j] = store[i][j] + pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1];//substacting the extra part
        }
    }

    int q; cin >> q;
    while(q--){
        int x1,y1,x2,y2,ans=0;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = pref_sum[x2][y2] - pref_sum[x1-1][y2] - pref_sum[x2][y1-1] + pref_sum[x1-1][y1-1]; // as we are subtracting 2 times the same portion subtracting twice so we are adding this once again
        cout << ans << "\n";
    }

}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin>>t;
    // while(t--){
    solve();
    //}

  return 0;
}