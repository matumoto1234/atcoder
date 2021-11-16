#include <bits/stdc++.h>
using namespace std;

struct zahyo {
  int y, x;
};

bool rangeCheck(int h, int w, int y, int x,int my,int mx) {
  if (y < mx || x < my || y >= h || x >= w) {
    return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<vector<int>> used(H, vector<int>(W, -1));
  vector<string> s(H);
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  int count = 0;
  int dirY[]={-1,0,1,0};
  int dirX[]={0,1,0,-1};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (used[i][j] != -1||s[i][j]=='#') {
        continue;
      }
      queue<zahyo> q;
      zahyo xy;
      xy.y = i;
      xy.x = j;
      q.push(xy);
      while (!q.empty()) {
        xy = q.front();
        q.pop();
        used[xy.y][xy.x] = count;
        for (int k = 0; k < 4; k++) {
          int ny=dirY[k]+xy.y;
          int nx=dirX[k]+xy.x;
          if(!rangeCheck(H,W,ny,nx,0,0)){
            continue;
          }
          if(s[ny][nx]=='#'){
            continue;
          }
          if(used[ny][nx]!=-1){
            continue;
          }
          xy.y=ny;
          xy.x=nx;
          q.push(xy);
        }
      }
      count++;
    }
  }

  int now=used[sy][sx];
  int goal=used[gy][gx];
  if(now==goal){
    cout<<0<<endl;
    return 0;
  }
  while(now!=goal){
    
  }

  /*
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(j){
        cout<<' ';
      }
      cout<<used[i][j];
    }
    cout<<endl;
  }*/
  return 0;
}