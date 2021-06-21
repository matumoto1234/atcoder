#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin>>n>>q;
  vector<int> imos(n+1,0);
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    imos[l]+=1;
    imos[r+1]+=-1;
  }
  for(int i=1;i<n;i++){
    imos[i]=imos[i-1]+imos[i];
  }

  for(int i=0;i<n;i++){
    cout<<imos[i]%2;
  }
  cout<<"\n";
  return 0;
}