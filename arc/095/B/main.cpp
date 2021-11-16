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
  int half=a[n-1]/2,ans=1e9;
  for(int i=0;i<n;i++){
    if(abs(half-ans)>=abs(half-a[i])&&n-1!=i){
      ans=a[i];
    }
  }
  cout<<a[n-1]<<" "<<ans<<endl;
  return 0;
}