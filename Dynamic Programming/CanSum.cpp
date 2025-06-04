// the problem is about a target sum and an array of numbers id the target sum is achiveable or not

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){

    ll tg,n; cin >> tg >> n;
    ll ar[n];
    for(int i=0; i<n; i++) cin >> ar[i];

    ll lewra[tg+1];

    memset(lewra,-1LL,sizeof(lewra));

    function<bool(ll)> target = [&](ll sum){

        if(sum == 0) return lewra[sum] = 1LL;
        if(sum < 0) return lewra[sum] = 0LL;
        if(lewra[sum] != -1) return lewra[sum];

        for(auto x : ar){
            ll check = sum - x;
            if(target(check)){
                return lewra[sum] = 1LL;
            }
        }

        return lewra[sum] = 0LL;
    };

    target(tg);

    cout << lewra[tg];

  return 0;
}
