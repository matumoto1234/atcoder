#include<bits/stdc++.h>
using namespace std;

int h,w;
bool range_check(int y,int x){
  return 0<=y&&y<h&&0<=x&&x<w;
}

int main(){
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }

  vector<vector<bool>> poss(h,vector<bool>(w));
  int dy[]={0,1,0,-1};
  int dx[]={1,0,-1,0};
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='.') continue;

      bool flg=false;
      for(int k=0;k<4;k++){
        int ny=i+dy[k];
        int nx=j+dx[k];
        if(range_check(ny,nx)==false) continue;
        if(s[ny][nx]=='#'){
          flg=true;
          break;
        }
      }
      poss[i][j]=flg;
      if(flg==false){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}