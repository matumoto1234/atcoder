#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(void){
    lli x;

    cin>>x;

    lli xx=120;

    for(lli i=-xx;i<=xx;i++){
        for(lli j=-xx;j<=xx;j++){
            lli temp=pow(i,5)-pow(j,5);
            if(temp==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

    return 0;
}