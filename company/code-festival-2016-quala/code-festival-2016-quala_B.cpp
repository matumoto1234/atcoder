#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n),b(n+1,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i+1]=a[i];
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    if(i==b[b[i]]){
      ans++;
      b[i]=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}