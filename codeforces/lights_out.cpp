#include<bits/stdc++.h>
using namespace std;

/*#define U ar1[i-1][j]
#define D ar1[i+1][j]
#define R ar1[i][j+1]
#define L ar1[i][j-1]
#define O ar1[i][j]*/

int main(){

int ar1[5][5]={{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
int ar2[5][5];
for(int i=1; i<4; i++){
    for(int j=1; j<4; j++){
        cin>>ar2[i][j];
        for(int k=1; k<=ar2[i][j]; k++){
            ar1[i][j]=(ar1[i][j]+1)%2;    // it's own index, if it's 0 the makes 1(%)
            ar1[i-1][j]=(ar1[i-1][j]+1)%2; //Up index
            ar1[i+1][j]=(ar1[i+1][j]+1)%2; //Down index
            ar1[i][j+1]=(ar1[i][j+1]+1)%2; //Right index
            ar1[i][j-1]=(ar1[i][j-1]+1)%2; //Left index
        }
    }
} 
for(int i=1; i<4; i++){
    for(int j=1; j<4;j++){
        cout<<ar1[i][j];
    }
    cout<<endl;
}

return 0;
}