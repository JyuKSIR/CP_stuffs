// https://cses.fi/problemset/task/1713/

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

void solve(){

    int n;
    cin >> n;
    
    int count = 1;

    for(int i=2; i*i <= n; i++){
        if(n%i == 0){
            int e = 0;
            while(n%i == 0){
                n/=i;
                e++;
            }
            count *= (e+1);
        }
    }
    if(n>1){
        count *= 2;
    }

    cout << count << "\n";
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
      solve();
    }

  return 0;
}
