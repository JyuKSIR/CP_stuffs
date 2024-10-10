// https://codeforces.com/contest/26/problem/A

// there shoud be two distinct prime like 2*3 or 2*3*3 | two or tre or as many prime can be multiple times but should be distinct can't be 2*2*2 or 3*3*3


#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 3005;
vector<int> primes;
bool isPrime[N];

void sieve() {

    for(int i=0; i<N; i++){
        isPrime[i] = true;
    }

    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            primes.push_back(i);
            for(int j=2*i; j<N; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){

    sieve();

    int n; cin >> n;
    int ans=0;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int a : primes){
            if(i % a == 0){
                count++;
            }
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
