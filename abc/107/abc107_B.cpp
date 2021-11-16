#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  vector<bool> g(h,false),r(w,false);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='#'){
        g[i]=true;
        r[j]=true;
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(g[i]&&r[j]){
        cout<<s[i][j];
      }
    }
    if(g[i]) cout<<"\n";
  }
  return 0;
}