#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a=0, cap=0;
    cin>>n;
    int arr[n][2];

    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>arr[i][j];
        }      
    }
    a=arr[0][1];
    cap=arr[0][1];
    for(int i=1; i<n; i++){
        for(int j=1; j<2; j++){
            a=(a-arr[i][j-1])+arr[i][j];
            if(a>cap){
                cap=a;
            }
        }
    }
cout<<cap;
return 0;
}