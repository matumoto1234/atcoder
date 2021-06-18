#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc,char* argv[]){
    lli n,temp;
    lli cnt=0;

    cin>>n;

    temp=100;
    while(1){
        temp*=1.01;
        cnt++;
        if(temp>=n){
            cout<<cnt<<endl;
            break;
        }
    }

    return 0;
}