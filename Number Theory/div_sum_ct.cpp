#include<bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main(){

  const int n = 1e5 + 5;
  vector<int> div[n];
  int sum[n]{};

  for(int i = 2; i < n; i++){
    for(int j = i; j < n; j += i){ 
      div[j].push_back(i);
      sum[j] += i;
    }
  }

  for(int i = 2; i <= 10; i++){
    printf("sum : %d\nct : %d\n", sum[i], (int)div[i].size());
    for(auto x : div[i]){
      printf("%d ", x);
    }
    printf("\n");
  }

 return 0;
}
TC - nlog(n)
