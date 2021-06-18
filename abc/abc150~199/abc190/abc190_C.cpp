#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n,m;
  cin>>n>>m;
  using P = pair<int,int>;
  vector<P> a(m);
  for(int i=0;i<m;i++){
    cin>>a[i].first>>a[i].second;
    a[i].first--;
    a[i].second--;
  }

  int k;
  cin>>k;
  vector<vector<int>> put(k,vector<int>(2));
  for(int i=0;i<k;i++){
    cin>>put[i][0]>>put[i][1];
    put[i][0]--;
    put[i][1]--;
  }

  int ans=0;
  for(int i=0;i<(1<<k);i++){
    vector<bool> ball(n,false);
    for(int j=0;j<k;j++){
      int idx=(i>>j)&1;
      ball[put[j][idx]]=true;
    }

    int cnt=0;
    for(int j=0;j<m;j++){
      int f=a[j].first;
      int s=a[j].second;
      if(ball[f]&&ball[s]) cnt++;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}