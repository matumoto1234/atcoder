#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  map<string,int> mp;
  for(int i=0;i<n;i++){
    cin>>s[i];
    mp[s[i]]++;
  }
  for(int i=0;i<n;i++){
    string t="!"+s[i];
    if(mp[t]>=1){
      cout<<s[i]<<endl;
      return 0;
    }
  }
  string sat = "satisfiable";
  cout<<sat<<endl;
  return 0;
}