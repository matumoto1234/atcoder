#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 100000;

vector<vector<int>> G(MAXN);
vector<int> dp(MAXN,0);

int dfs(int idx){
  int &res=dp[idx];
  if(res!=0){
    return res;
  }
  //cerr<<"idx:"<<idx<<endl;

  for(int e:G[idx]){
    res=max(res,dfs(e)+1);
  }
  return res;
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int from,to;
    cin>>from>>to;
    from--;
    to--;
    G[from].emplace_back(to);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    //cerr<<"start"<<endl;
    ans=max(ans,dfs(i));
  }
  cout<<ans<<endl;
  return 0;
}