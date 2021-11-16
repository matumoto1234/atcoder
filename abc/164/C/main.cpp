#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(int argc,char* argv[]){
    int n,ans=1;
    cin>>n;
    vector<string> s(n);

    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}