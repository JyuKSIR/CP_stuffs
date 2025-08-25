#include<bits/stdc++.h>
using namespace std;

struct DSU{

  vector<int> par,sz, b;
  int k;

  DSU(int n) : par(n + 1), sz(n + 1, 1), b(n + 1, 0){
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
      b[i] += b[j];
    }
  }

  void add(int i){
    i = find(i);
    b[i]++;
  }

  void rem(int i){
    i = find(i);
    b[i]--;
  }

  bool has(int i){
    i = find(i);
    return b[i] > 0;
  }

};

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n,q; cin >> n >> q;

  DSU dsu(n);
  vector<int> col(n + 1, 0);  // initially all are while
  // while = 0
  // black = 1

  while(q--){
    int ty; cin >> ty;
    if(ty == 1){
      int u,v; cin >> u >> v;
      dsu.join(u,v);
    }
    else if(ty == 2){
      int u; cin >> u;
      if(col[u] == 0){     // if white make it black
        col[u] = 1;
        dsu.add(u);
      }
      else{
        col[u] = 0;        // if black make it white
        dsu.rem(u);
      }
    }
    else{
      int u; cin >> u;
      if(dsu.has(u)){
        cout << "Yes\n";
      }
      else cout << "No\n";
    }
  }
  return 0;
}
// https://atcoder.jp/contests/abc420/tasks/abc420_e
