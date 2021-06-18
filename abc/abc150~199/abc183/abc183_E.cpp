#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

struct xyz{
  ll x,y,z;
  xyz():x(0),y(0),z(0){}
};

int main(){
  ll h,w;
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  vector<vector<ll>> dp(h,vector<ll>(w,0));
  dp[0][0]=1;
  vector<vector<xyz>> rui(h,vector<xyz>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        continue;
      }
      if(j>0) rui[i][j].x=(rui[i][j-1].x+dp[i][j-1])%p;
      if(i>0) rui[i][j].y=(rui[i-1][j].y+dp[i-1][j])%p;
      if(i>0&&j>0) rui[i][j].z=(rui[i-1][j-1].z+dp[i-1][j-1])%p;
      dp[i][j]+=rui[i][j].x+rui[i][j].y+rui[i][j].z;
      dp[i][j]%=p;
    }
  }
  /*
  cout<<"---dp---\n";
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<dp[i][j]<<' ';
    }
    cout<<endl;
  }
  */
  cout<<dp[h-1][w-1]<<endl;
  return 0;
}