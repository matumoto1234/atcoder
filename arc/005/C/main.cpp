#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct zahyo{
  int y,x;
  zahyo(){}
  zahyo(int y,int x):y(y),x(x){}
};

bool range_check(int h,int w,int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int main(){
  int h,w;
  cin>>h>>w;

  int sy,sx,gy,gx;
  vector<vector<char>> c(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c[i][j];
      if(c[i][j]=='s'){
        sy=i;
        sx=j;
      }
      if(c[i][j]=='g'){
        gy=i;
        gx=j;
      }
    }
  }

  int dy[]={1,0,-1,0};
  int dx[]={0,1,0,-1};
  vector<vector<int>> arrived(h,vector<int>(w,-1));
  deque<zahyo> Q;
  arrived[sy][sx]=0;
  Q.emplace_back(sy,sx);
  while(!Q.empty()){
    zahyo p=Q.front();
    Q.pop_front();

    for(int i=0;i<4;i++){
      int ny=p.y+dy[i];
      int nx=p.x+dx[i];

      if(!range_check(h,w,ny,nx)) continue;
      if(arrived[ny][nx]!=-1) continue;
      if(c[ny][nx]=='#'){
        Q.emplace_back(ny,nx);
        arrived[ny][nx]=arrived[p.y][p.x]+1;
      }else{
        Q.emplace_front(ny,nx);
        arrived[ny][nx]=arrived[p.y][p.x];
      }
    }
  }
  cout<<(arrived[gy][gx]<=2?"YES":"NO")<<endl;
  return 0;
}