#include<bits/stdc++.h>
using namespace std;
int main(){
  int h1, m1, h2, m2, k;

  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int s1, s2;
  s1 = h1 * 60 + m1;
  s2 = h2 * 60 + m2;
  cout << s2 - s1 - k << endl;
  return 0;
}