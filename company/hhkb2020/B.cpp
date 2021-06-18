#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  int ans=0;
  int dirY[]={1,0};
  int dirX[]={0,1};
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){


      for(int k=0;k<2;k++){
        int ny,nx;
        ny=dirY[k]+i;
        nx=dirX[k]+j;
        if(ny>=h||nx>=w){
          continue;
        }
        if(s[ny][nx]=='.'&&s[i][j]=='.'){
          ans++;
        }
      }

    }
  }
  cout<<ans<<endl;
  return 0;
}