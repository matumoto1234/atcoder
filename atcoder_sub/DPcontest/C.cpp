#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int MAXN = 100000;

vector<vector<ll>> a(MAXN,vector<ll>(3));
vector<vector<ll>> done(MAXN,vector<ll>(3,-1));
ll calc(ll now,ll kind){
  if(now==0){
    return a[0][kind];
  }

  ll &res=done[now][kind];
  if(res!=-1){
    return res;
  }
  for(int i=0;i<3;i++){
    if(i==kind) continue;
    res=max(res,calc(now-1,i)+a[now][kind]);
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
      cin>>a[i][j];
    }
  }
  cout<<max(calc(n-1,0),max(calc(n-1,1),calc(n-1,2)))<<endl;
  return 0;
}