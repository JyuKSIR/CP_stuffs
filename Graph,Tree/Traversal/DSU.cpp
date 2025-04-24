#include<bits/stdc++.h>
using namespace std;

struct DSU{

    vector<int> par,sz;
    int k;

    DSU(int n) : par(n + 1), sz(n + 1, 1){
        k = n;
        for (int i = 1; i <= n; ++i) par[i] = i;
    }

    int find(int i){
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int get_size(int i){
        return sz[find(i)];
    }

    int count(){
        return k;
    }

    void join(int i,int j){
        i = find(i);
        j = find(j);
        if(i != j){
            k--;
            if(sz[i] < sz[j]){
                swap(i,j);
            }
            par[j] = i;
            sz[i] += sz[j];
        }
    }
};

int main(){

    

  return 0;
}

//https://www.youtube.com/watch?v=zEAmQqOpfzM
