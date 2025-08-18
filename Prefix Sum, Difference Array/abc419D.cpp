#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  int n,q; scanf("%d%d", &n, &q);
  string s1,s2; cin >> s1 >> s2;
  int da[n+1]{};
  while(q--){
    int l,r; scanf("%d%d", &l, &r);
    l--,r--;
    da[l]++;
    da[r+1]--;
  }

  partial_sum(da, da+n+1, da);

  for(int i = 0; i < n; i++){
    if(da[i] & 1){
      swap(s1[i],s2[i]); //the odd one will swap cause for even its the same s[i] after even moves
    }
  }
  cout << s1;

 return 0;
}
//https://atcoder.jp/contests/abc419/tasks/abc419_d
