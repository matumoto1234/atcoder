#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string s;
  cin>>n>>s;
  vector<int> a(n+1,0),b(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='W'){
      a[i+1]+=a[i]+1;
    }else{
      a[i+1]=a[i];
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='E'){
      b[max(i-1,0)]+=b[i]+1;
    }else{
      b[max(i-1,0)]=b[i];
    }
  }
  int ans=1e9;
  for(int i=0;i<n;i++){
    ans=min(a[i]+b[i],ans);
  }
  cout<<ans<<endl;
  return 0;
}