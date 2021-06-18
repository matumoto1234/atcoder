#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
using namespace std;
using ll = long long;

vector<ll> sum_f(vector<ll>& a,int sz){
  vector<ll> res;
  for(int i=0;i<(1<<sz);i++){
    ll sum=0;
    for(int j=0;j<sz;j++){
      if(i>>j&1){
        sum+=a[j];
      }
    }
    res.push_back(sum);
  }
  sort(res.begin(),res.end());
  return res;
}

ll nibun(vector<ll>& a,ll upper){
  ll l=0,r=(ll)a.size();
  while(r-l>1){
    ll mid=(l+r)/2;
    if(a[mid]<=upper){
      l=mid;
    }else{
      r=mid;
    }
  }
  return a[l];
}

int main(){
  ll n,t;
  cin>>n>>t;
  int sz=(n/2)+(n%2?1:0);
  vector<ll> a(sz),b(n/2);
  for(int i=0;i<sz;i++){
    cin>>a[i];
  }
  for(int i=0;i<n/2;i++){
    cin>>b[i];
  }

  vector<ll> sum1=sum_f(a,sz);
  vector<ll> sum2=sum_f(b,n/2);
  
  ll ans=-1LL;
  for(int i=0;i<(1<<sz);i++){
    ll temp=sum1[i];
    if(temp>t) break;

    //cerr<<"temp:"<<temp<<" nibun:"<<nibun(sum2,t-temp)<<endl;
    temp+=nibun(sum2,t-temp);
    if(temp>t) continue;
    ans=max(ans,temp);
  }
  cout<<ans<<endl;
  return 0;
}