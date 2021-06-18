#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = INT64_MAX/2;

int main(){
  ll n,c;
  cin>>n>>c;
  vector<vector<ll>> D(c,vector<ll>(c));
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      cin>>D[i][j];
    }
  }

  vector<vector<ll>> grid(n,vector<ll>(n));
  vector<vector<ll>> cnt(3,vector<ll>(c,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
      int col=grid[i][j]-1;
      int grp=(i+j)%3;
      cnt[grp][col]++;
    }
  }

  ll ans=INF;
  for(int i=0;i<c;i++){
    for(int j=0;j<c;j++){
      if(i==j) continue;
      for(int k=0;k<c;k++){
        if(i==k||j==k) continue;
        ll v1,v2,v3;
        v1=v2=v3=0;
        for(int col=0;col<c;col++) v1+=cnt[0][col]*D[col][i];
        for(int col=0;col<c;col++) v2+=cnt[1][col]*D[col][j];
        for(int col=0;col<c;col++) v3+=cnt[2][col]*D[col][k];
        ans=min(ans,v1+v2+v3);
      }
    }
  }
  cout<<ans<<endl;
}