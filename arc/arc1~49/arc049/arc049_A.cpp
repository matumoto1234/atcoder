#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  vector<int> a(4);
  for(int i=0;i<4;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  for(int i=0;i<4;i++){
    s.insert(s.begin()+a[i]+i,'"');
  }
  cout<<s<<endl;
  return 0;
}