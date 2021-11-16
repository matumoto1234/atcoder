#include<bits/stdc++.h>
using namespace std;
int main(){
  map<string,int> mp;
  int n;
  cin>>n;
  int maxv=-1;
  string ans;
  vector<string> name(n);
  for(int i=0;i<n;i++){
    cin>>name[i];
    mp[name[i]]++;
    if(maxv<mp[name[i]]){
      ans=name[i];
      maxv=mp[name[i]];
    }
  }
  cout<<ans<<endl;
  return 0;
}