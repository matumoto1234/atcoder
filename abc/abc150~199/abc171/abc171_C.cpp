#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  ll keta=26,count=1;
  while(1){
    if(n<=keta){
      break;
    }
    n-=keta;
    keta*=26;
    count++;
  }
  n--;
  string ans="";
  while(count>0){
    count--;
    //cout<<n<<endl;
    ans.push_back('a'+n%26);
    n/=26;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}