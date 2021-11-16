#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int cnt=0,last=a[0];
  int ans=0;
  for(int i=0;i<n;i++){
    if(last==a[i]){
      cnt++;
    }else{
      ans+=cnt%2;
      last=a[i];
      cnt=1;
    }
  }
  if(last==a[n-1]){
    ans+=cnt%2;
  }
  cout<<ans<<endl;
}