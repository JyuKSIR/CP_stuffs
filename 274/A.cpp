// https://atcoder.jp/contests/abc001/tasks/abc001_4?lang=en
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  string a[n];
  vector<array<int,2>> v, ans;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    string st = "", en = "";
    for(int j = 0; j < 4; j++){
      st += a[i][j];
      en += a[i][5 + j];
    }
    v.push_back({stoi(st), stoi(en)});
  }
  for(auto &[a, b] : v){
    a -= a % 5;
    if(b % 5){
      b -= b % 5;
      b += 5;
    }
    // after this step, let a time is 1157 it was becoming 1160 but no
    // such time doesn't exists so we will add 40 and make 1160 to 1200
    if(b % 100 == 60) b += 40;
  }
  sort(v.begin(), v.end());
  int p = v[0][0];
  int q = v[0][1];
  for(int i = 1; i < n; i++){
    if(q >= v[i][0]){
      q = max(q, v[i][1]);
    }
    else{
      ans.push_back({p, q});
      p = v[i][0];
      q = v[i][1];
    }
  }
  ans.push_back({p,q});
  for(auto [a, b] : ans){
    cout << setw(4) << setfill('0') << a << "-"
    << setw(4) << setfill('0') << b << "\n";
  }
}
