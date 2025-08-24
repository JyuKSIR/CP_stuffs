#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll expo(ll a,ll b){
  ll ans = 1;
  while(b){
    if(b & 1ll){
      ans = ans * a;
    }
    a = a * a;
    b >>= 1ll;
  }
  return ans;
}

ll digitsumtilln(ll n, vector<ll> &a) {
  if (n < 10) return n * (n + 1) / 2;
  ll d = (ll)(log10(n));
  ll p = expo(10, d);
  ll msd = n / p;
  return (msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) +
          digitsumtilln(n % p, a));
}
 
ll digitsum(ll n) {
  ll d = max((ll)(log10(n)), 1ll);
  vector<ll> a(d + 1);
  a[0] = 0;
  a[1] = 45;
  for (int i = 2; i <= d; i++) {
    a[i] = a[i - 1] * 10 + 45 * (expo(10, i - 1));
  }
  return digitsumtilln(n, a);
}

ll kthdigitsum(ll n){
  ll digit = 1, base = 9;
  while(n > base * digit){
    n -= (base * digit);
    base *= 10;
    digit++;
  }
  ll extra = (n - 1) / digit;
  ll num = expo(10, digit - 1) + extra;
  ll ans = digitsum(num - 1);
  ll ind = (n - 1) % digit;
  string s = to_string(num);
  for(int i = 0; i <= ind; i++){
    ans += (s[i] - '0');
  }
  return ans;
}

void solve(){
  ll n; cin >> n;
  cout << kthdigitsum(n) << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t; cin >> t;
  
  while(t--){
    solve();
  }
 return 0;
}
