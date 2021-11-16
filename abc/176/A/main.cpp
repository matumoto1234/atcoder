#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,x,t;
  cin >> n>>x>>t;
  int sum=n/x;
  if(n%x!=0){
    sum++;
  }
  cout<<sum*t<<endl;
  return 0;
}