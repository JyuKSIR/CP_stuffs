//Euclid algo : a*b/gcd(a,b) = lcm(a,b)
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  cout << gcd(12,18) <<"\n";
  cout << "LCM: " << 12*18 / gcd(12,18);
}