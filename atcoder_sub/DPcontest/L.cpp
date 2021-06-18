#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll MAXN = 3000;
const ll INF = INT64_MAX/2;

vector<ll> a(MAXN);
vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(MAXN+2,vector<ll>(MAXN+2,-INF)));

ll next_turn(ll t) { return !t; }

/* [l,r)で考える。turn 0:太郎、turn 1:次郎 */
ll dfs(ll turn,ll l,ll r){
  if(l+1==r){
    return a[l];
  }
  if(l+2==r){
    if(turn==0){
      return max(a[l],a[l+1])-min(a[l],a[l+1]);
    }else{
      return min(a[l],a[l+1])-max(a[l],a[l+1]);
    }
  }

  ll& res = dp[turn][l][r];
  if(res!=-INF){
    return res;
  }

  ll begin=a[l];
  ll end=a[r-1];

  if(turn==0){
    ll v1=begin+dfs(next_turn(turn),l+1,r);
    ll v2=dfs(next_turn(turn),l,r-1)+end;
    res=max(v1,v2);
    return res;
  }else{
    ll v1=dfs(next_turn(turn),l+1,r)-begin;
    ll v2=dfs(next_turn(turn),l,r-1)-end;
    res=min(v1,v2);
    return res;
  }
}

int main(){
  ll N;
  cin>>N;
  for(ll i=0;i<N;i++){
    cin>>a[i];
  }
  cout<<dfs(0,0,N)<<endl;

  return 0;
}