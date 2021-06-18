#include<iostream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin>>s;

  int n=(int)s.size();
  int ans=50;
  bool flg=false;
  for(ll i=1;i<(1<<n);i++){
    string t;
    int cnt=n;
    for(int j=0;j<n;j++){
      if(i>>j&1){
        t+=s[j];
        cnt--;
      }
    }
    /*
    ll num = stoll(t);
    if (num % 3LL == 0) {
      ans = min(ans, cnt);
      flg = true;
    }
    */
    try {
      ll num = stoll(t);
      if (num % 3LL == 0) {
        ans = min(ans, cnt);
        flg=true;
      }
    } catch (const invalid_argument &e) {
      continue;
    } catch (const out_of_range &e) {
      continue;
    }
  }
  if(flg==false){
    cout<<-1<<endl;
    return 0;
  }
  cout<<ans<<endl;
  return 0;
}