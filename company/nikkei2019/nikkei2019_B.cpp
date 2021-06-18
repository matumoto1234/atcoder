#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, sum = 0;
  vector<string> s(3);
  vector<int> cnt(3, 0);
  cin >> n >> s[0] >> s[1] >> s[2];
  for (int i = 0; i < n;i++){
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int j = 0; j < 3;j++){
      for (int k = 0; k < 3;k++){
        if(j==k){
          cnt[j]++;
          continue;
        }
        if(s[j][i]==s[k][i]){
          cnt[j]++;
        }
      }
    }
    sum += 3 - max(cnt[0], max(cnt[1], cnt[2]));
  }
  cout << sum << endl;
  return 0;
}