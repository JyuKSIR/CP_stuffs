// https://www.spoj.com/problems/TDPRIMES/

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const long long N = 100000000;
vector<long long> primes;
bool isPrime[N+1];

void solve(){

    fill(isPrime,isPrime+N,true);

    isPrime[0] = isPrime[1] = false;
    for(long long i = 2; i*i <= N; i++){
        if(isPrime[i]){
            for(long long j = i*i; j<=N; j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    for(long long p = 2; p<=N; p++){
        if(isPrime[p]){
            primes.push_back(p);
        }
    }

    for(long long i = 0; i < (long long) primes.size(); i+=100){
        cout << primes[i] << "\n";
    }
}

int main(){

    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
      solve();
    

  return 0;
}