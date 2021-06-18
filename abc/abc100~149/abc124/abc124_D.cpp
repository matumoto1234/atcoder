#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  
  using P = pair<int,int>;
  vector<P> v;
  v.emplace_back(1,0);
  for(int i=0;i<n;i++){
    int tmp=s[i]-'0';
    if(v.back().first!=tmp) v.emplace_back(tmp,0);
    v.back().second++;
  }
  if(v.back().first==0) v.emplace_back(1,0);

  int m=(int)v.size();
  vector<int> r(m+1,0);
  for(int i=0;i<m;i++){
    r[i+1]=r[i]+v[i].second;
  }

  int ans=0;
  int add=min(2*k+1,m);
  for(int i=0;i<=m-add;i+=2){
    ans=max(ans,r[i+add]-r[i]);
  }

  cout<<ans<<endl;
}