#include<bits/stdc++.h>
using namespace std;

void div_count_sum(int n, int &count, int &sum){ // n = 24 , pf = 2^3 * 3

    count = 1;
    sum = 1;

    for(int i=2; i*i <= n; i++){         // count = (3+1) * (1+1)  ---> power/exponential + 1 --> generalized formula : (e1+1) * (e2+1)
        if(n%i == 0){
            int e = 0,baseSum = 1;       // sum = ((2^0) + (2^1) + (2^2) + (2^3)) * ((3^0) + (3^1)) --> generalized formula : (p^(e+1) - 1) / (p - 1) for each prime  -->> p=2,3 || e = 3,1
            while(n%i == 0){ // work for composite
                n/=i;
                e++;
                baseSum = baseSum * i + 1;
            }
            count *= (e+1);
            sum *= baseSum;
        }  
    }
    if(n>1){                // there coulb be a prime in last like 2*2*2*(3) that's why this condition
        count *= 2;   // (1 + 1) for the prime itself
        sum *= (n+1);  // (p^(1+1) - 1) / (p - 1)
    }
}

int main(){

    int n;
    cin >> n;
    
    int ct = 0, sum = 0;

    div_count_sum(n,ct,sum);  // passing ct to count by reff so changing in count means changing in ct

    cout << ct << " " << sum;

  return 0;
}