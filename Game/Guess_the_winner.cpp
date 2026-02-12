// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// bool f(int n, bool t){
//   bool w = 0;
//   int m = n;
//   vector<int> p;
//   for(int i = 2; i <= n; i++){
//     while(n % i == 0){
//       p.push_back(i);
//       n /= i;
//     }
//   }
//   for(auto i : p){
//     if(i > 2){
//        w |= !f(m - i, !t);
//     }
//   }
//   return w;
// }

// int main(){
//   cin.tie(0)->sync_with_stdio(0);
  
//   for(int i = 1; i <= 20; i++){
//     if(f(i, 0)) cout << "Alice\n";
//     else cout << "Bob\n";
//   }

// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
  int n; cin >> n;
  if(n == 1 || n % 2 == 0) cout << "Bob\n";
  else cout << "Alice\n";
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
}

