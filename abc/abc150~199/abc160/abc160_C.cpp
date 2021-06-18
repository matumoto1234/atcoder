#include<iostream>
#include<vector>
using namespace std;
int main(){
  int k,n;
  cin>>k>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> sa(n+1,0);
  sa[0]=a[0]-0;
  sa[n]=k-a[n-1];
  int sum=sa[0]+sa[n];
  for(int i=1;i<n;i++){
    sa[i]=a[i]-a[i-1];
    sum+=sa[i];
  }

  int ans=min(sum-(sa[n]+sa[0]),sum-sa[1]);
  for(int i=1;i<n;i++){
    int now;
    now=min(sum-sa[i],sum-sa[i+1]);
    ans=min(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}