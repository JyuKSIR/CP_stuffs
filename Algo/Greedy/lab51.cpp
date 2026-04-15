#include <iostream>
using namespace std;

int main() {
  int n, a; cin >> n >> a;
  int ar[n];
  for(int i = 0; i < n; i++) cin >> ar[i];
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < n - 1 - i; j++){
      if(ar[j] < ar[j + 1]){
        swap(ar[j], ar[j + 1]);
      }
    }
  }
  int ct = 0;
  for(int i = 0; i < n; i++){
    if(a == 0){
      break;
    }
    int t = a / ar[i];
    ct += t;
    a -= t * ar[i];
  }
  if(a != 0) cout << "Can't be done";
  else cout << ct;
}
