#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,k;
    long long summax=0;

    cin>>a>>b>>c>>k;
    if(a>=k){
        cout<<k<<endl;
        return 0;
    }else{
        summax+=a;
        k-=a;
    }
    if(b>=k){
        cout<<summax<<endl;
        return 0;
    }else{
        k-=b;
    }
    summax-=k;
    cout<<summax<<endl;
    return 0;
}