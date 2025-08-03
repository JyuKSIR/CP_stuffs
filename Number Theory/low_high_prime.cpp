#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  const int n = 1e7 + 5;
  vector<int> vis(n,1), lp(n,-1), hp(n);

  vis[0] = vis[1] = 0;

  for(int i = 2; i < n; i++){
    if(vis[i]){
      lp[i] = hp[i] = i;
      for(int j = 2 * i; j < n; j += i){
        vis[j] = 0;
        hp[j] = i;
        if(lp[j] == -1) lp[j] = i;
      }
    }
  }

  // for(int i = 1; i <= 20; i++){
  //   printf("%d\n%d %d\n", vis[i], lp[i], hp[i]);
  // }

  int x; cin >> x;
  unordered_map<int,int> um;

  while(x > 1){
    int pf = hp[x];
    while(x % pf == 0){
      x /= pf;
      um[pf]++;
    }
  }

  for(auto [a,b] : um){
    printf("%d %d\n",a,b);
  }

 return 0;
}
