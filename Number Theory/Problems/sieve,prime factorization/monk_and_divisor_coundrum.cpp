#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  const int x = 2e5+5;
  vector<int> fq(x,0),ct(x,0);
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int p; scanf("%d", &p);
    fq[p]++;
  }
  for(int i = 1; i < x; i++){
    for(int j = i; j < x; j += i){
      ct[i] += fq[j];
    }
  }
  int m; scanf("%d", &m);
  while(m--){
    int p,q; scanf("%d%d", &p, &q);
    int ans = ct[p] + ct[q];
    ll z = (p * 1LL * q) / __gcd(p,q); // common multiples of p,q by lcm
    if(z < x) ans -= ct[z];
    printf("%d\n", ans);
  }

 return 0;
}

// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
