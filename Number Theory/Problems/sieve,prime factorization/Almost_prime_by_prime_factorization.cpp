// https://codeforces.com/contest/26/problem/A

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

void solve(){
    
    int n; cin >> n;

    int ans=0;

    for(int i=2; i<=n; i++){
        int count=0;
        int x=i;
        for(int j=2; j*j <= n; j++){
            if(x%j == 0){
                count++;
                while(x%j == 0){
                    x/=j;
                }
            }
        }
        if(x>1){
            count++;
        }
        if(count == 2){
            ans++;
        }
    }
    cout << ans << "\n";

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

  return 0;
}