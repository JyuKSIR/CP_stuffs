//Euclid algo : a*b/gcd(a,b) = lcm(a,b)
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ct=0, sum=0;
    cin >> n;
    for(int i =1; i*i <= n; i++){
        if(n % i == 0){
            cout << i << " " << n/i << "\n";
            ct++;
            sum+=i;
            if(n/i != i){
                ct++;
                sum+=n/i;
            }
        }
    }
    cout << "count of divisors: " << ct << " Sum: " << sum << "\n";
}

// time complexity O(sqrt(n))
