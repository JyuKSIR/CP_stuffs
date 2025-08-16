// how many numbers from 1 to n are coprime of n
#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  int n; scanf("%d", &n);

  auto phi = [](int x) -> int {
    int ct = x;
    for(int i = 2; i * i <= x; i++){
      if(x % i == 0){
        while(x % i == 0){
          x /= i;
        }
        ct *= (i-1);
        ct /= i;
      }
    }
    if(x > 1){
      ct *= (x-1);
      ct /= x;
    }
    return ct;
  };

  int ans = phi(n);
  printf("%d", ans);

 return 0;
}
TC :- O(sqrt(n))
