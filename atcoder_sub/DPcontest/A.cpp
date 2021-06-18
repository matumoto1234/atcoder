#include<iostream>
#include<vector>
using namespace std;
const int INF = 100100100;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> dp(n,INF);
  dp[0]=0;
  dp[1]=abs(a[1]-a[0]);
  for(int i=2;i<n;i++){
    int tmp=dp[i-1]+abs(a[i]-a[i-1]);
    int tmp2=dp[i-2]+abs(a[i]-a[i-2]);
    dp[i]=min(tmp,tmp2);
  }
  cout<<dp[n-1]<<endl;
  return 0;
}