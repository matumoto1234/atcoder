#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.rbegin(),t.rend());
  //cout<<s<<" "<<t<<endl;
  cout<<(s<t?"Yes":"No")<<endl;
  return 0;
}