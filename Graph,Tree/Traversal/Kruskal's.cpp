 #include<bits/stdc++.h>
 using namespace std;

 struct DSU{

    vector<int> par,sz;
    int c;

    DSU(int n) : par(n+1,0),sz(n+1,1){
        c = n;
        for(int i=1; i<=n; i++) par[i] = i;
    }

    int find(int i){
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int count(){
        return c;
    }

    void join(int i,int j){
        i = find(i);
        j = find(j);
        if(i != j){
            c--;
            if(sz[i] < sz[j]) swap(i,j);
            par[j] = i;
            sz[i] += sz[j];
        }
    }
};
 
 int main(){
    
    int n,m; cin >> n >> m;

    vector<array<int,3>> g,mst;

    for(int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        g.push_back({w,u,v});
    }

    sort(g.begin(),g.end());

    int mst_cost = 0;

    DSU d(n);

    for(auto ed : g){
        int w = ed[0] , u = ed[1] , v = ed[2];
        if(d.same(u,v)) continue;
        mst_cost += w;
        d.join(u,v);
        mst.push_back({u,v,w});
    }

    cout << mst_cost << "\n";
    for(auto x : mst) cout << x[0] << " " << x[1] << " " << x[2] << "\n";

    cout << "\n";
 
   return 0;
 }
// https://www.youtube.com/watch?v=xDrLSOxaFrA
