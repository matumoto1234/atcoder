#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
using ld = long double;

ld dp[101][101][101];

void init(){
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      for(int k=0;k<=100;k++){
        dp[i][j][k]=-2.0;
      }
    }
  }
}

ld dfs(int x,int y,int z){
  ld &res=dp[x][y][z];
  if(dp[x][y][z]>-1.0){
    return res;
  }
  res=0.0;
  if(max({x,y,z})==100){
    return res;
  }
  res+=dfs(x+1,y,z)*(ld)x/(ld)(x+y+z);
  res+=dfs(x,y+1,z)*(ld)y/(ld)(x+y+z);
  res+=dfs(x,y,z+1)*(ld)z/(ld)(x+y+z);
  res+=1.0;
  return res;
}

int main(){
  init();
  cout<<fixed<<setprecision(10);
  ld a,b,c;
  cin>>a>>b>>c;
  //cout<<dfs(a,b,c)<<endl;
  for(int i=a;i<=100;i++){
    for(int j=b;j<=100;j++){
      for(int k=c;k<=100;k++){
        
      }
    }
  }
  return 0;
}
/*
dp[i][j][k]
Px=(x)/(x+y+z)
Py=(y)/(x+y+z)
Pz=(z)/(x+y+z)
dp[i+1][j][k]+=(dp[i][j][k]+1)*Px
dp[i][j+1][k]+=(dp[i][j][k]+1)*Py
dp[i][j][k+1]+=(dp[i][j][k]+1)*Pz
*/