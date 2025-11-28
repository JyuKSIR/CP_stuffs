#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

vector<ll> bin(ll n) {
  vector<ll> pows;
  if (n == 0) pows.push_back(0);
  else {
    while (n > 0) {
      pows.push_back(n % 2);
      n /= 2;
    }
  }
  return pows;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;
  vector<ll> pow = bin(n);
  int p = (pow.size() + 7 - 1) / 7;
  vector<ll> ans;
  string s = "";
  for(int i = 0; i < (int)pow.size(); i++){
    s += ((pow[i] == 1) ? '1' : '0');
    if((i + 1) % 7 == 0){
      reverse(s.begin(), s.end());
      bitset<7> bb(s);
      ll num = bb.to_ulong();
      s = "";
      ans.push_back(num);
    }
  }
  if(!s.empty()){
    reverse(s.begin(), s.end());
    while(s.size() < 7) s = '0' + s;
    bitset<7> bb(s);
    ll num = bb.to_ulong();
    s = "";
    ans.push_back(num);
  }
  reverse(ans.begin(), ans.end());
  for(int i = 0; i < (int)ans.size(); i++){
    if(i + 1 < p) cout << ans[i] + 128 << " ";
    else cout << ans[i] << " ";
  }  
  return 0;
}
// https://qoj.ac/contest/2658/problem/15409
