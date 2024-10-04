// Basic segmented sieve as the teory

#include<bits/stdc++.h>
using namespace std;

vector<long long> primes; // 2,3,5,7

void sieve(long long a){

    long long x = sqrt(a); // Sqrt(100) = 10

    vector<bool> is_prime(x,true); 

    is_prime[0] = is_prime[1] = false;

    for(long long i=2; i <= x; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(long long j = i*i; j<= x; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

void segSieve(long long k, long long l){ // k = 50 , l = 100

    long long x = (l-k)+1; // l = 100-50+1 = 51 

    vector<bool> is_prime(x,true);

    for(long long g : primes){
        for(long long i = k; i<=l; i++){
            if(i % g == 0){
                is_prime[i-k] = false; // i=50 k=50   is_prime[50-50] = is_prime[0]
            }
        }
    }

    for(long long j = k; j<=l; j++){
        if(is_prime[j-k]){
            cout << j << " ";
        }
    }
}

int main(){

   long long n,m; // n=50 ,m= 100

   cin >> n >> m;
    
    sieve(m);
    
    segSieve(n,m);

    // for(long long p : primes){
    //     cout << p << " ";
    // }

  return 0;
}
