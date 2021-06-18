#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m+2);
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  a[m]=0;
  a[m+1]=n+1;
  m+=2;
  sort(a.begin(),a.end());
  int l=n+2;
  int ans=0;
  for(int i=1;i<m;i++){
    int w=a[i]-a[i-1]-1;
    if(w==0) continue;
    l=min(l,w);
  }
  for(int i=1;i<m;i++){
    int w=a[i]-a[i-1]-1;
    ans+=(w+l-1)/l;
  }
  cout<<ans<<endl;
  return 0;
}