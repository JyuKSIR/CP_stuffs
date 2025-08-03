#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  const int N = 1e7 + 5;
  vector<int> vis(N,1), lp(N,-1);

  vis[0] = vis[1] = 0;

  for(int i = 2; i < N; i++){
    if(vis[i]){
      lp[i] = i;
      for(int j = 2 * i; j < N; j += i){
        vis[j] = 0;
        if(lp[j] == -1) lp[j] = i;
      }
    }
  }

  int n;
  while (scanf("%d", &n) != EOF) {
    vector<int> pf;
    while(n > 1){
      int prf = lp[n];
      while(n % prf == 0){
        pf.push_back(prf);
        n /= prf; 
      }
    }
    printf("1");
    for(auto x : pf) printf(" x %d", x);
    printf("\n");
  }
  
 return 0;
}
// prime factorization by sieve
// https://www.spoj.com/problems/FACTCG2/
