#include<bits/stdc++.h>
using namespace std;

struct zahyo{
  int y,x;
};

bool rangeCheck(int y,int x,int h,int w){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

int main(){
  int h,w;
  int sy,sx,gy,gx;
  cin>>h>>w;
  cin>>sy>>sx>>gy>>gx;
  sy--;
  sx--;
  gy--;
  gx--;
  
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }

  int dirY[]={0,1,0,-1};
  int dirX[]={1,0,-1,0};
  queue<zahyo> Q;
  vector<vector<int>> arrived(h,vector<int>(w,-1));
  zahyo start;
  start.y=sy;
  start.x=sx;
  arrived[sy][sx]=0;
  Q.push(start);
  while(!Q.empty()){
    zahyo temp=Q.front();
    Q.pop();

    if(temp.y==gy&&temp.x==gx){
      break;
    }

    for(int i=0;i<4;i++){
      int ny=dirY[i]+temp.y;
      int nx=dirX[i]+temp.x;

      if(!rangeCheck(ny,nx,h,w)) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[ny][nx]!=-1) continue;

      arrived[ny][nx]=arrived[temp.y][temp.x]+1;
      zahyo nextXY;
      nextXY.y=ny;
      nextXY.x=nx;
      Q.push(nextXY);
    }
  }
  cout<<arrived[gy][gx]<<endl;
  return 0;
}