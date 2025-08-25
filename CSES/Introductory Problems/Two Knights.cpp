#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

  ll n; cin >> n;
  for(ll i = 1; i <= n; i++){
    ll comb = ((i * i) * ((i * i) - 1)) / 2;
    ll inval = 4 * (i - 1) * (i - 2);
    cout << comb - inval << "\n";
  }

 return 0;
}
// https://www.youtube.com/watch?v=RlpM5N-ttcU
