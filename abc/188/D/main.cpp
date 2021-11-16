#include <bits/stdc++.h>
#define int long long
using namespace std;
using P = pair<int,int>;

signed main() {
  int n,c;
  cin>>n>>c;

  map<int,int> mp;
  for(int i=0;i<n;i++){
    int x,y,z;
    cin>>x>>y>>z;
    mp[x]+=z;
    mp[y+1]-=z;
  }

  int sum=0;
  for(auto &e:mp){
    sum+=e.second;
    e.second=sum;
  }

  int prev=0;
  int ans=0;
  for(auto e:mp){
    if(prev==0){
      prev=e.first;
      continue;
    }
    int h=mp[prev];
    int w=e.first-prev;
    ans+=min(h*w,c*w);
    prev=e.first;
  }
  cout<<ans<<endl;
  return 0;
}