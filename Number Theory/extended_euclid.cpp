// https://www.youtube.com/watch?v=6KmhCKxFWOs  --> the implementation how it works

#include<bits/stdc++.h>
using namespace std;

#define dbg(a) cerr<<__LINE__<<" no. line: "<<#a<<" = "<<a<<endl

long long extended_euclid(long long a, long long b, long long &x, long long &y){

    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long x1,y1;
    long long d = extended_euclid(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1; 
    return d;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a,b,s,t;

    a = 56;
    b = 15;
    long long gcd = extended_euclid(a,b,s,t);

    cout << gcd << " " << s << " " << t << '\n';

  return 0;
}