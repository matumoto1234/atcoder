#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> t(n);
  int sum=0;
  for (int i = 0; i < n; i++){
    cin >> t[i];
    sum += t[i];
  }
  int m;
  cin >> m;
  vector<int> p(m), x(m);
  for (int i = 0; i < m;i++){
    cin >> p[i] >> x[i];
    int tmp = sum;
    tmp -= t[p[i] - 1];
    tmp += x[i];
    cout << tmp << endl;
  }
  return 0;
}