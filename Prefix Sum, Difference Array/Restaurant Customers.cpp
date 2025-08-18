#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  int n; scanf("%d", &n);
  vector<array<int,2>> v;
  
  while(n--){
    int l,r; scanf("%d%d", &l, &r);
    v.push_back({l, 1});
    v.push_back({r+1, -1});
  }

  sort(v.begin(),v.end());

  for(int i = 1; i < v.size(); i++){
    v[i][1] += v[i-1][1];
  }

  int mx = -1e9;

  for(auto [p,q] : v){
    if(mx < q){
      mx = q;
    }
    //printf("%d %d\n", p, q);
  }

  printf("%d", mx);

 return 0;
}
//https://cses.fi/problemset/task/1619/
