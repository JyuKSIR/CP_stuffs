#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> toBase(ll n, int b) {
  vector<ll> pows;
  if (n == 0) pows.push_back(0);
  else {
    while (n > 0) {
      pows.push_back(n % b); // remainder is the current digit
      n /= b;                  // move to next place
    }
    //reverse(pows.begin(), pows.end()); // put in normal order
  }
  return pows;
}

int main(){
  ll n; 
  int b;
  cin >> n >> b;

  vector<ll> p = toBase(n, b);

  cout << n << " in base " << b << "\n";
  for (int i = 0; i < p.size(); i++) cout << i << " " << p[i] << "\n";
}
