#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin>>n>>s;
  vector<int> a(26,0);
  for(int i=0;i<n;i++){
    a[s[i]-'a']++;
  }
  vector<int> b(n,0);
  int ans=0;
  for(int i=0;i<n;i++){
    b[s[i]-'a']++;
    a[s[i]-'a']--;
    int sum=0;
    for(int j=0;j<26;j++){
      if (a[j] > 0 && b[j] > 0) {
        sum++;
      }
    }
    ans=max(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}