#include<bits/stdc++.h>
using namespace std;

struct zahyo{
  int y,x;
};

bool rangeCheck(int y,int x,int h,int w){
  if(y<0||x<0||y>=h||x>=w) return false;
  return true;
}

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }

  int sy,sx;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='s'){
        sy=i;
        sx=j;
        goto EXIT;
      }
    }
  }
EXIT:

  bool answer=false;
  int dirY[]={1,0,-1,0};
  int dirX[]={0,1,0,-1};
  vector<vector<int>> arrived(h,vector<int>(w,-1));
  arrived[sy][sx]=0;
  stack<zahyo> st;
  zahyo start;
  start.y=sy;
  start.x=sx;
  st.push(start);
  while(!st.empty()){
    zahyo now=st.top();
    st.pop();

    if(s[now.y][now.x]=='g'){
      answer=true;
      break;
    }

    for(int i=0;i<4;i++){
      int ny=dirY[i]+now.y;
      int nx=dirX[i]+now.x;

      if(!rangeCheck(ny,nx,h,w)) continue;
      if(s[ny][nx]=='#') continue;
      if(arrived[ny][nx]!=-1) continue;

      arrived[ny][nx]=arrived[now.y][now.x]+1;
      zahyo nextXY;
      nextXY.y=ny;
      nextXY.x=nx;
      st.push(nextXY);
    }
  }
  cout<<(answer?"Yes":"No")<<endl;
  return 0;
}