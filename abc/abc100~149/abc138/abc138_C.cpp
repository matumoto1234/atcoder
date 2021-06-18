#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
//#include"cxx-prettyprint/prettyprint.hpp"
#include<math.h>
using namespace std;



int main(int argc,char *argv[]){
    
    int n;
    vector<double> v(50);
    double ans=0.0;

    cin>>n;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<double>());
    
    for(int i=0;i<n;i++){
        if(i==n-1)ans+=v[i]/pow(2.0,(double)n-1.0);
        else ans+=v[i]/pow(2.0,(double)i+1.0);
    }
    cout<<ans<<endl;

    return 0;
}