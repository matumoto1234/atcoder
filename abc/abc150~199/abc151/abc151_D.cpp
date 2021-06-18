#include<bits/stdc++.h>
using namespace std;

struct zahyo{
  int y,x;
};

int h,w;
vector<string> s(20);

bool rangeCheck(int y,int x){
  if(y<0||y>=h||x<0||x>=w){
    return false;
  }
  return true;
}

int main(){
  cin>>h>>w;
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  int dirY[]={0,1,0,-1};
  int dirX[]={1,0,-1,0};
  int ans=-1;

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        continue;
      }
      int cntmax=-1;
      vector<vector<int>> cnt(h,vector<int> (w,-1));
      queue<zahyo> q;
      zahyo xy;
      xy.y=i;
      xy.x=j;
      q.push(xy);
      cnt[i][j]=0;
      while(!q.empty()){
        xy=q.front();
        q.pop();
        cntmax=max(cntmax,cnt[xy.y][xy.x]);
        for(int k=0;k<4;k++){
          int ny=dirY[k]+xy.y;
          int nx=dirX[k]+xy.x;
          if(rangeCheck(ny,nx)==false){
            continue;
          }
          if(s[ny][nx]=='#'){
            continue;
          }
          if(cnt[ny][nx]!=-1){
            continue;
          }
          cnt[ny][nx]=cnt[xy.y][xy.x]+1;
          zahyo temp;
          temp.y=ny;
          temp.x=nx;
          q.push(temp);
        }
      }
      ans=max(cntmax,ans);
    }
  }
  cout<<ans<<endl;
  return 0;
}