#include<bits/stdc++.h>
#define ll long long
#define ld long double
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

  ordered_set<array<int,2>> os;
  int n,q; scanf("%d%d", &n, &q);
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
    os.insert({a[i],i});
  }
  while(q--){
    char c; cin >> c;
    if(c == '!'){
      int k,x; scanf("%d%d", &k, &x);
      k--;
      os.erase({a[k],k});
      os.insert({x,k});
      a[k] = x;
    }
    else{
      int a, b; scanf("%d%d", &a, &b);
      int ans = os.order_of_key({b+1,0}) - os.order_of_key({a,0}); // between a,b so we did b+1 - a which includes b
      printf("%d\n", ans);
    }
  }

 return 0;
}
O((n+q)log(n))
