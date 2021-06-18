#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }

  int ans=0;
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      int cnt=0;
      for(int ki=0;ki<h;ki++){
        for(int kj=0;kj<w;kj++){
          if(i>>ki&1||j>>kj&1){
            continue;
          }
          if(s[ki][kj]=='#') cnt++;
        }
      }
      if(cnt==k) ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}