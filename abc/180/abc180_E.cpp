#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll MAXN = 17;
const ll MAXV=(1LL<<MAXN);
const ll INF = INT64_MAX/2LL;

struct zahyo{
  ll x,y,z;
};

ll N,V;
vector<zahyo> ds(MAXN);
vector<vector<ll>> dp(MAXN+1,vector<ll>(MAXV+1,INF));

template <typename T1,typename T2>
void chmin(T1& a,T2 b){
  if(a>b){
    a=b;
  }
}

ll calc(zahyo from,zahyo to){
  return abs(from.x-to.x)+abs(from.y-to.y)+max(0LL,to.z-from.z);
}

ll dfs(ll idx,ll visited){
  //cerr<<"idx:"<<idx<<" visited:"<<visited<<endl;
  if(visited==V-1){
    return calc(ds[idx],ds[0]);
  }

  ll& res=dp[idx][visited];
  if(res!=INF){
    return res;
  }

  for(ll i=0;i<N;i++){
    if(i==idx) continue;
    if(visited>>i&1) continue;
    ll cost=calc(ds[idx],ds[i]);
    //cerr<<"cost:"<<cost<<" i:"<<i<<endl;
    chmin(res,dfs(i,visited+(1LL<<i))+cost);
  }
  return res;
}

int main(){
  cin>>N;
  V=(1LL<<N);
  for(ll i=0;i<N;i++){
    cin>>ds[i].x>>ds[i].y>>ds[i].z;
  }
  cout<<dfs(0LL,1LL)<<endl;
  return 0;
}