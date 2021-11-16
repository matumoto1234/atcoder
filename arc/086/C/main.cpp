#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, k, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> a(n), list(n + 1, 0);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(list[a[i]]==0){
      cnt++;
    }
    list[a[i]]++;
  }
  if(cnt<=k){
    cout << 0 << endl;
    return 0;
  }
  sort(list.begin(), list.end());
  for (int i = 0;i<=n;i++){
    if(list[i]==0)
      continue;
    sum += list[i];
    cnt--;
    if(cnt<=k){
      break;
    }
  }
  cout << sum << endl;
  return 0;
}