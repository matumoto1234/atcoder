#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<vector>
#define P 1000000000+7
typedef long long int lli;
using namespace std;

int main(void){
    lli n,k;
    lli min,max;

    cin>>n>>k;
    lli sum=0;
    for(lli i=k;i<=n+1;i++){
        min=(2*0+(i-1)*1)*i/2;
        max=(2*n+(i-1)*-1)*i/2;
        //cout<<"min="<<min<<" max="<<max<<endl;

        sum+=max-min+1;
        sum%=P;
    }
    cout<<sum<<endl;
    return 0;
}