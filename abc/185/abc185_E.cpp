#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = 100100100;
const int MAXN = 1000;
const int MAXM = 1000;

vector<vector<int>> dp(MAXN+1,vector<int>(MAXM+1,INF));
vector<int> a(MAXN),b(MAXM);
int dfs(int i,int j){
  if(i==0) return j;
  if(j==0) return i;

  int& res=dp[i][j];
  if(res!=INF) return res;

  if(a[i-1]==b[j-1]){
    res=min(dfs(i-1,j)+1,dfs(i,j-1)+1);
    res=min(res,dfs(i-1,j-1));
  }else{
    res=min(dfs(i-1,j)+1,dfs(i,j-1)+1);
    res=min(res,dfs(i-1,j-1)+1);
  }
  return res;
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<m;i++){
    cin>>b[i];
  }
  cout<<dfs(n,m)<<endl;
  return 0;
}