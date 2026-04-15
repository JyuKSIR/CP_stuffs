#include <iostream>
using namespace std;

int main() {
  int n; cin >> n;
  int s[n], f[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) cin >> f[i];
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - 1 - i; j++){
      if(f[j] > f[j + 1]){
        swap(f[j], f[j + 1]);
        swap(s[j], s[j + 1]);
      }
    }
  }
  int lf = f[0];
  int ct = 1;
  for(int i = 0; i < n; i++){
    if(s[i] >= lf){
      ct++;
      lf = f[i];
    }
  }
  cout << ct;
}
