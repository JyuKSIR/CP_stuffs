#include<bits/stdc++.h>
using namespace std;

int main(){

   int Y,W,D;
   cin>>Y>>W;
   int max=(Y>W ? Y: W);
   D=7-max;
   int a;
   int b;
   if(6%D==0){
      a=D/D;
      b=6/D;
     cout<<a<<"/"<<b;
   }
   else if(D%2==0){
      a=D/2;
      b=3;
      cout<<a<<"/"<<b;
   }
   else{
      cout<<D<<"/"<<6;
   }
return 0;
}