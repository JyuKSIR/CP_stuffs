#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

void test(ll n){

  ll ct = 0;
  while(n % 2 == 0){ // Handle factor 2 separately (because it's the only even prime)
    ct++;
    n /= 2;
  }

  if(ct > 0){
    printf("2^%lld ",ct);
  }
  // Now check odd factors from 3 up to sqrt(n)
  for(ll i = 3; i*i <= n; i+=2){
    ll ct = 0;
    while(n % i == 0){
      ct++;
      n /= i;
    }
    if(ct > 0){
      printf("%lld^%lld ", i, ct);
    }
  }
  // If n is a prime number > 2 at the end
  if(n>1){
    printf("%lld^1", n);
  }

  printf("\n");
}

int main(){

  ll x;
  while (scanf("%lld", &x) && x != 0){
    test(x);
  }

 return 0;
}

//https://www.spoj.com/problems/FACT0/
TC - 	O(√n)
