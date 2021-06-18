#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int a[12][12];

int main(void){
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> c(n);
    loop(i,n){
        cin>>c[i];
        loop(j,m){
            cin>>a[i][j];
        }
    }

    int ans=INT_MAX;
    loop(s,1<<n){
        int cost=0;
        vector<int> d(m);
        loop(i,n){
            if(s>>i&1){
                cost+=c[i];
                loop(j,m){
                    d[j]+=a[i][j];
                }
            }
        }
        bool ok=true;
        loop(j,m){
            if(d[j]<x){
                ok=false;
            }
        }
        if(ok==true){
            ans=min(ans,cost);
        }
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}