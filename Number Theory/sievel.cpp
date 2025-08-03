#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  const int n = 1e7 + 5;
  vector<int> vis(n,1);

  vis[0] = vis[1] = 0;

  for(int i = 2; i < n; i++){
    if(vis[i]){
      for(int j = 2 * i; j < n; j += i){
        vis[j] = 0;
      }
    }
  }

  for(int i = 1; i <= 20; i++){
    cout << vis[i] << " ";
  }

 return 0;
}
