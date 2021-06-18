#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> d(k),list(n,0);
    vector<vector<int>> a(k,vector<int>(100));

    for(int i=0;i<k;i++){
        cin>>d[i];
        for(int j=0;j<d[i];j++){
            cin>>a[i][j];
            list[a[i][j]-1]=1;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(list[i]==0){
            cnt++;
        }
    }

    cout<<cnt<<endl;;

    return 0;
}