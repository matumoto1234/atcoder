#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int sum=0;
  for(int i=1;i<=n;i++){
    sum+=i*i;
  }
  cout<<sum%m<<endl;
  return 0;
}