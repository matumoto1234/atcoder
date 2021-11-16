#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k, cnt = 0;
  cin >> n >> m;
  vector<int> list(m, 0);
  for (int i = 0; i < n;i++){
    cin >> k;
    vector<int> a(k);
    for (int j = 0; j < k;j++){
      cin >> a[j];
      list[a[j] - 1]++;
    }
  }
  for (int i = 0; i < m;i++){
    if(list[i]==n){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}