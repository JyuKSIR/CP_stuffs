#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int phi[N];
vector<int> primes;

void linear_totient() {
  phi[1] = 1;
  for(int i = 2; i < N; i++) {
    if(!phi[i]){           // i is prime
      phi[i] = i - 1;      // φ(p) = p-1 if p is prime
      primes.push_back(i);
    }
    for(int p : primes) {
      if(1LL * i * p >= N) break;
      if(i % p == 0){
        phi[i * p] = phi[i] * p;  // prime divides i
        break;
      } 
      else{
        phi[i * p] = phi[i] * (p - 1); // prime does not divide i
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  linear_totient();

  for (int i = 1; i <= 20; i++) {
    cout << "phi(" << i << ") = " << phi[i] << "\n";
  }

  return 0;
}

TC :- O(n);
