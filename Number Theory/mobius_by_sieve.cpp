// --> watch introduction part for basic
// reference -->  https://www.youtube.com/watch?v=fmTDMdi3QWY&t=1537s


#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

vector<int> mobius_by_sieve(int n){

    vector<int> mobius(n+1,1);
    vector<bool> is_prime(n+1,true);

    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            // checking for multiple of prime i
            for(int j = i; j <= n; j += i){
                is_prime[j] = false;
                mobius[j] *= -1;
            }
            // checking for multiples of i^2
            for(int k = i*i; k <= n; k += i*i){
                mobius[k] = 0;
            }
        }
    }
    return mobius;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> show = mobius_by_sieve(n);

    for(int i=1; i<=n ; i++){
        cout << "μ(" << i << ") = " << show[i] << endl;
    }

  return 0;
}