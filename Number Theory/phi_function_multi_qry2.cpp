// https://www.youtube.com/watch?v=uaF4HvRrW08 --> by prime factorization can understand the basic theorem

// ---> by sieve


#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

const int N = 1e5 + 9;

int phi[N];

void totient_by_prime(){
    
    for(int i=0; i<= N; i++){
        phi[i] = i;
    }

    for(int i = 2; i <= N; i++){
        if(phi[i] == i){
           for(int j = i; j <= N; j += i){
            //cout << "i: " << i << " " <<phi[j] << "\n";
            phi[j] -= phi[j]/i;  // when you divide 6 by 2 and the ans is 3 it means there are 3 multiple of 2 between 1 and 6 which are
                                 // 2,4,6 and it means gcd(2,6),gcd(4,6),gcd(6,6) can't be 1 so we are minusing 3 from 6 
            //cout << "j: " << j << " " << phi[j] << "\n";
           } 
        }
    }

    for(int i = 2; i<=1000; i++){
        cout << phi[i] << " ";
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    totient_by_prime();

  return 0;
}
TC :- O(NloglogN)
