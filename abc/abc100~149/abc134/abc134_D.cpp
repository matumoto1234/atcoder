#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m=0;
  vector<int> ans(n+1,0);
  for(int i=n;i>=1;i--){
    int sum=0;
    for(int j=i*2;j<=n;j+=i){
      sum+=ans[j];
    }
    //cout << "i=" << i << " sum=" << sum << endl;
    if(sum%2!=a[i]){
      m++;
      ans[i]=1;
    }
  }
  cout<<m<<endl;
  bool flg=false;
  for(int i=1;i<=n;i++){
    if(ans[i]){
      if(flg){
        cout<<' ';
      }
      cout<<i;
      flg=true;
    }
  }
  if(m){
    cout<<endl;
  }
  return 0;
}