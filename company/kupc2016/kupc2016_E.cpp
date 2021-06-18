#include<bits/stdc++.h>
using namespace std;

struct zahyo{
  int y,x;
};

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

void bfs(vector<vector<char>>& s,vector<vector<int>>& group,int h,int w,int sy,int sx,int& id){
  if(group[sy][sx]!=-1){
    return;
  }
  if(s[sy][sx]=='X'){
    return;
  }

  int dirY[] = {1, 0, -1, 0};
  int dirX[] = {0, 1, 0, -1};
  zahyo init;
  init.y=sy;
  init.x=sx;
  queue<zahyo> Q;
  Q.push(init);
  group[sy][sx]=id;
  bool flg=false;

  while(!Q.empty()){
    zahyo now=Q.front();
    Q.pop();
    
    for(int i=0;i<4;i++){
      int ny=now.y+dirY[i];
      int nx=now.x+dirX[i];

      if(!range_check(h,w,ny,nx)){
        continue;
      }
      if(s[ny][nx]=='X'){
        continue;
      }
      if(group[ny][nx]!=-1){
        continue;
      }

      zahyo Next;
      Next.y=ny;
      Next.x=nx;
      Q.push(Next);

      group[ny][nx]=id;
      flg=true;

    }
  }
  if(flg){
    id++;
  }
}

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }

  for(int i=0;i<h;i++){
    if(s[i][0]=='X'||s[i][w-1]=='X'){
      cout<<-1<<endl;
      return 0;
    }
  }
  for(int j=0;j<w;j++){
    if(s[0][j]=='X'||s[h-1][j]=='X'){
      cout<<-1<<endl;
      return 0;
    }
  }


  int id=0;
  vector<vector<int>> group(h,vector<int>(w,-1));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      bfs(s,group,h,w,i,j,id);
    }
  }


  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){

    }
  }


  return 0;
}