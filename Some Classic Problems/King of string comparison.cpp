#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;
  string s, t; cin >> s >> t;
  ll ans = 0, in = -1;
  bool f = 0;

  for(int i = n - 1; ~i; i--){
    if(s[i] != t[i]){
      in = i;
      if(s[in] < t[in]) f = 1;
      else f = 0;
    }
    if(in != -1 && f){
      ans += (n - in);
    }
  }
  cout << ans;
  
  return 0;
}
