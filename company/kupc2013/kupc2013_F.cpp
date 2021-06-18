#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,s;
  cin>>n>>s;
  int minv=1e9,maxv=0;
  vector<int> l(n),r(n);
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
    
  }
  cout<<maxv-minv<<endl;
  return 0;
}