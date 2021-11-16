#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

typedef struct{
    int a,b;
    int ai,bi;
}aaa;
typedef struct{
    int h,i;
}bbb;

int main(void){
    int n,m;
    cin>>n>>m;

    vector<int> flg(n,0);
    vector<bbb> h(n);
    vector<aaa> a(m);

    for(int i=0;i<n;i++){
        cin>>h[i].h;
        h[i].i=i;
    }

    for(int i=0;i<m;i++){
        cin>>a[i].a>>a[i].b;
        flg[a[i].a-1]=1;
        flg[a[i].b-1]=1;
        a[i].ai=a[i].a-1;
        a[i].bi=a[i].b-1;
        a[i].a=h[a[i].a-1].h;
        a[i].b=h[a[i].b-1].h;
    }
    //sort(h.begin(),h.end());
    //sort(a.begin(),a.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(flg[i]==0){
            cnt++;
            //cout<<"---"<<i<<endl;
        }
    }
    for(int i=0;i<m;i++){
        if(a[i].a>=a[i].b){
            flg[a[i].bi]=0;
        }
        if(a[i].b>=a[i].a){
            flg[a[i].ai]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(flg[i]==1){
            cnt++;
            //cout<<i<<endl;
        }
    }

    /*
    for(int i=0;i<m;i++){
        cout<<a[i].a<<" "<<a[i].b<<endl;
    }*/

    cout<<cnt<<endl;
    return 0;
}