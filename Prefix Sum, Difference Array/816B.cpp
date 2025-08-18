#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){
  const int N = 2e5+5;
  int n,k,q;
  scanf("%d%d%d", &n, &k, &q);
  int da[N]{}, ans[N]{};
  for(int i = 1; i <= n; i++){
    int l,r;
    scanf("%d%d", &l, &r);
    da[l]++;
    da[r+1]--;
  }
  partial_sum(da,da+N,da);
  for(int i = 1; i <= N; i++){
    if(da[i] >= k) ans[i]++;
  }
  partial_sum(ans,ans+N,ans);
  for(int i = 0; i < q; i++){
    int l,r;
    scanf("%d%d", &l, &r);
    printf("%d\n", ans[r] - ans[l-1]);
  }
 return 0;
}
