#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n,q; cin >> n >> q;
 
    vector<int> t[n];
    int d[n]{},anc[n][20]{}; // log2(2*10^5)
 
    for(int i=1; i<n; i++){
        int p; cin >> p;
        p--; // 0 based
        t[p].push_back(i);
    }
 
    function<void(int,int)> dfs = [&](int n,int p){
        anc[n][0] = p;
        for(int j=1; j<20; j++){
            if(anc[n][j-1] == -1){
                anc[n][j] = -1;
            }
            else{
                anc[n][j] = anc[ anc[n][j-1] ][j-1];
            }
        }
 
        for(auto c : t[n]){
            if(c != p){
                d[c] = d[n] + 1;
                dfs(c,n);
            }
        }
    };
 
    function<int(int,int)> kth = [&](int u,int k){
        for(int j = 19; ~j; j--){
            if( (k >> j) & 1) u = anc[u][j];
            if(u == -1) break;
        }
        return u;
    };
    dfs(0,-1);
    while(q--){
        int x,k; cin >> x >> k;
        x--;
        if(d[x]<k){
            cout << "-1\n";
        }
        else cout << kth(x,k)+1 << "\n";
    }
 
  return 0;
}
