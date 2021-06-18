#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  string s,t;
  cin>>s>>t;
  int ans=1e9;
  for(int i=0;i<s.size();i++){
    int temp=0;
    int ji=0;
    for(int j=i;j-i<t.size();j++){
      if(j>=s.size()){
        temp=1e9;
        break;
      }
      if(s[j]!=t[ji]){
        temp++;
      }
      ji++;
    }
    ans=min(ans,temp);
    //cout<<temp<<endl;
  }
  cout<<ans<<endl;
  return 0;
}