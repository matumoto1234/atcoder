#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MOD = (int)1e9+7;

struct zahyo{
  int y,x;
  zahyo(){}
  zahyo(int y,int x):y(y),x(x){}
};

bool range_check(int y,int x,int h,int w){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int main(){
  int dy[]={-1,0,1,0};
  int dx[]={0,-1,0,1};
  int h,w;
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }

  vector<vector<int>> dp(h,vector<int>(w,0));
  vector<vector<bool>> arrived(h,vector<bool>(w,false));
  queue<zahyo> Q;
  Q.emplace(0,0);
  arrived[0][0]=true;
  dp[0][0]=1;
  while(!Q.empty()){
    zahyo now=Q.front();
    Q.pop();
    //cerr<<"y:"<<now.y<<" x:"<<now.x<<endl;

    for(int i=0;i<4;i++){
      int ny=now.y+dy[i];
      int nx=now.x+dx[i];

      if(!range_check(ny,nx,h,w)) continue;
      if(s[ny][nx]=='#') continue;
      if(i<2){
        dp[now.y][now.x]+=dp[ny][nx];
        dp[now.y][now.x]%=MOD;
        continue;
      }
      if(arrived[ny][nx]) continue;

      Q.emplace(ny,nx);
      arrived[ny][nx]=true;
    }
  }
  cout<<dp[h-1][w-1]<<endl;

//  for(int i=0;i<h;i++){
//    for(int j=0;j<w;j++){
//      cerr<<dp[i][j]<<' ';
//    }
//    cerr<<endl;
//  }
  return 0;
}