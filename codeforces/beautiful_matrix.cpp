
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,l,ans, arr[5][5];

    for(i=0; i<5;i++){
        for(j=0; j<5;j++){
          cin>>arr[i][j];
          if(arr[i][j]==1)
          {
              k=2-i;
              l=2-j;
          }
       }
    }
    ans=abs(k)+abs(l);
    cout<<ans;
   return 0;
}
