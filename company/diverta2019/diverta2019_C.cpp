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
  int index=distance(a.begin(),upper_bound(a.begin(),a.end(),-1));
  if(index==0){
    index=1;
  }else if(index==n){
    index=n-1;
  }
  int temp=a[0];
  int sum1=a[0],sum2=a[n-1];
  for(int i=index;i<n-1;i++){
    sum1-=a[i];
  }
  a[0]=sum1;
  for(int i=0;i<index;i++){
    sum2-=a[i];
  }
  cout<<sum2<<endl;
  a[0]=temp;
  sum1=a[0],sum2=a[n-1];
  for(int i=index;i<n-1;i++){
    cout<<sum1<<' '<<a[i]<<"\n";
    sum1-=a[i];
  }
  a[0]=sum1;
  for(int i=0;i<index;i++){
    cout<<sum2<<' '<<a[i]<<"\n";
    sum2-=a[i];
  }
  return 0;
}