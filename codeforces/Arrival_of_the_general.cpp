#include<bits/stdc++.h>
using namespace std;

int main(){

int n, max=0, min=0, maxindex=0, minindex=0, sec;
cin>>n;
int ar[n];
for(int i=0; i<n; i++){
    cin>>ar[i];
}
max=ar[0];
min=ar[0];
for(int i=0; i<n; i++){
    if(max<ar[i]){
        max=ar[i];
        maxindex=i;
    }
    if(min>=ar[i]){
        min=ar[i];
        minindex=i;
    }
}
if(maxindex>minindex){
    minindex++;
}
sec=maxindex+((n-1)-minindex);
cout<<sec;

return 0;
}