#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const int N = 2e5 + 5;
int a[N];
array<int,4> t[4*N]; // dont declare it in ST it will give segmentation fault

struct ST{
  void bld(int n, int b, int e){
    if(b == e){
      t[n] = {a[b], 1, 0, 0};
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    bld(l, b, m);
    bld(r, m+1, e);

    map<int,int> mp;
    // left child
    auto [lw,lx,ly,lz] = t[l];
    mp[lw] += lx;
    mp[ly] += lz;
    // right child
    auto [rw,rx,ry,rz] = t[r];
    mp[rw] += rx;
    mp[ry] += rz;

    vector<array<int,2>> v;

    for(auto [p,q] : mp){
      v.push_back({p,q});
    }

    sort(v.rbegin(),v.rend());

    auto [aa,bb] = v[0]; // after reverse sorting largest
    auto [cc,dd] = v[1]; // after reverse sorting second largest

    t[n] = {aa, bb, cc, dd};

  }
  void upd(int n, int b, int e, int i, int x){
    if (b > i || e < i) return;
    if(b == e && b == i){
      a[i] = x;
      t[n] = {a[b], 1, 0, 0};
      return;
    }
    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    upd(l, b, m, i, x);
    upd(r, m+1, e, i, x);

    map<int,int> mp;
    // left child
    auto [lw,lx,ly,lz] = t[l];
    mp[lw] += lx;
    mp[ly] += lz;
    // right child
    auto [rw,rx,ry,rz] = t[r];
    mp[rw] += rx;
    mp[ry] += rz;

    vector<array<int,2>> v;

    for(auto [p,q] : mp){
      v.push_back({p,q});
    }

    sort(v.rbegin(),v.rend());

    auto [aa,bb] = v[0]; // after reverse sorting largest
    auto [cc,dd] = v[1]; // after reverse sorting second largest

    t[n] = {aa, bb, cc, dd};

  }
  array<int,4> qry(int n, int b, int e, int i, int j){
    if(b > j || e < i) return {0,0,0,0};
    if(b >= i && e <= j) return t[n];

    int m = (b + e) >> 1, l = (n << 1) + 1 , r = (n << 1) + 2;
    array<int,4> L = qry(l, b, m, i, j);     // left child
    array<int,4> R = qry(r, m + 1, e, i, j); // right child

    map<int,int> mp;
    // left child
    auto [lw,lx,ly,lz] = L;
    mp[lw] += lx;
    mp[ly] += lz;
    // right child
    auto [rw,rx,ry,rz] = R;
    mp[rw] += rx;
    mp[ry] += rz;

    vector<array<int,2>> v;

    for(auto [p,q] : mp){
      v.push_back({p,q});
    }

    sort(v.rbegin(),v.rend());

    auto [aa,bb] = v[0]; // after reverse sorting largest
    auto [cc,dd] = v[1]; // after reverse sorting second largest

    return {aa, bb, cc, dd};
  }
};

int main(){
  int n,q; scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  ST tree;
  tree.bld(0,0,n-1);

  // for(int i = 0; i < 10; i++){
  //   for(int j = 0; j < 4; j++){
  //     printf("%d ", t[i][j]);
  //   }
  //   printf("\n");
  // }

  while(q--){
    int a,b,c; scanf("%d%d%d", &a, &b, &c);
    if(a == 1){
      b--;
      tree.upd(0,0,n-1,b,c);
      continue;
    }
    b--,c--;
    auto p = tree.qry(0,0,n-1,b,c);
    printf("%d\n", p[3]);
  }
 return 0;
}

//https://atcoder.jp/contests/abc343/tasks/abc343_f
TC : O(n+qlog(n))
