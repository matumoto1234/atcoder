#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
using ld = long double;
const int MAXN = 2999;

int n;
vector<ld> p(n);
vector<vector<ld>> dp(MAXN,vector<ld>(MAXN,-2.0));
ld dfs(int i,int j){
  if(i==0&&j==0){
    return 1.0;
  }

  ld &res=dp[i][j];
  if(res>-1.0){
    return res;
  }
  res=dfs(i-1,j)*p[i]+dfs(i-1,j-1)*(1.0-p[i]);
  return res;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>p[i];
  }
  cout<<fixed<<setprecision(10);
  int m=n/2+1;
  cout<<dfs(n,m)<<endl;
  return 0;
}