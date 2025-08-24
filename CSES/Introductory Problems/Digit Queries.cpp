#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

  auto expo = [](ll a, ll b) -> ll{
    ll ans = 1;
    while(b){
      if(b & 1ll){
        ans = ans * a;
      }
      a = a * a;
      b >>= 1ll;
    }
    return ans;
  };

  ll q; cin >> q;
  while(q--){
    ll n; cin >> n;
    ll digit = 1, base = 9;
    while(n > digit * base){
      n -= (digit * base);
      base *= 10;
      digit++;
    }

    ll extra = (n - 1) / digit;  // n-1 -> 0 based indexing 
    ll num = expo(10, digit - 1) + extra; // extra -> ekok, doshok, shotok ghorer number
    ll ind = (n - 1) % digit; // index;

    string s = to_string(num);
    cout << s[ind] << "\n";
  }

 return 0;
}
// https://www.youtube.com/watch?v=RF2vLHdk4Rs&t=1054s
// https://cses.fi/problemset/task/2431/
