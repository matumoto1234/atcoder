#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  using P = pair<double,double>;
  vector<P> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
  }
  int ans=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(abs((v[i].second-v[j].second)/(v[i].first-v[j].first))<=1){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}