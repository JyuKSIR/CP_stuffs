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

    int n,k; cin >> n >> k;
    DSU d(n);
    while(k--){
        int u,v; cin >> u >> v;
        d.join(u,v);
    }
    cout << d.count() << "\n";

  return 0;
}
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
