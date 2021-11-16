#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, a, b, ans = 0;
  cin >> n >> a >> b;
  for (int i = 1; i <= n;i++){
    int temp = i, sum = 0;
    while(temp>0){
      sum += temp % 10;
      temp /= 10;
    }
    if(sum>=a&&sum<=b){
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}