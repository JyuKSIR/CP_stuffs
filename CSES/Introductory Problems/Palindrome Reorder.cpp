// https://cses.fi/problemset/task/1755/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  string s; cin >> s;
  int fq[26]{};
  for (int i = 0; i < (int)s.size(); i++) {
    fq[s[i] - 'A']++;
  }
  int od = -1, oct = 0;
  char c;
  for (int i = 0; i < 26; i++) {
    if (fq[i] & 1) {
      oct++;
      c = (char)(i + 65);
      od = fq[i];
      fq[i] = 0;
    }
  }
  if (oct > 1) {
    cout << "NO SOLUTION";
    return 0;
  }
  for (int i = 0; i < 26; i++) {
    if (fq[i]) {
      char x = (char)(i + 65);
      string ss(fq[i] / 2, x);
      cout << ss;
    }
  }
  if (od != -1) {
    string m(od, c);
    cout << m;
  }
  for (int i = 25; ~i ; i--) {
    if (fq[i]) {
      char x = (char)(i + 65);
      string ss(fq[i] / 2, x);
      cout << ss;
    }
  }
}
