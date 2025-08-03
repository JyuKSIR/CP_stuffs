#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const int n = 1e6+5;
vector<int> vis(n,1),ctq(n,0);

void solve(){

  vis[0] = vis[1] = 0;
  for(int i = 2; i < n; i++){
    if(vis[i]){
      for(int j = 2 * i; j < n; j += i){
        vis[j] = 0;
      }
    }
  }

  auto ok = [](int n)-> bool{
    int t = 10;
    bool c = 1;
    while(n % t != n){
      int x = n % t;
      if(!vis[x]){
        c = 0;
        break;
      }
      t *= 10;
    }
    return c;
  };

  auto zero = [](int n)-> bool{
    bool c = 0;
    while(n){
      if(n % 10 == 0){
        c = 1;
        break;
      }
      n /= 10;
    }
    return c;
  };

  for(int i = 2; i < n; i++){
    if(vis[i]){
      if(!ok(i)){
        vis[i] = 0;
      }
      if(zero(i)){
        vis[i] = 0;
      }
    }
  }

  int ct = 0;
  
  for(int i = 2; i < n; i++){
    if(vis[i]) ct++;
    ctq[i] = ct;
  }

}

int main(){


  solve();
  int t; cin >> t;

  while(t--){
    int num; scanf("%d", &num);
    printf("%d\n", ctq[num]);
   }

 return 0;
}