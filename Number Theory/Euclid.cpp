//Euclid algo : a*b/gcd(a,b) = lcm(a,b)
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}

int gcd_ternary(int a,int b){
  return b ? gcd(b, a%b) : a;
}

int gcd_nonrecursive(int a, int b){
  while(b){
    a %= b;
    swap(a,b);
  }
  return a;
}

int main(){
  cout << gcd(12,18) <<"\n";
  cout << "LCM: " << 12*18 / gcd(12,18);
}
