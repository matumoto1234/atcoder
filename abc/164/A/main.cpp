#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc, char *argv[]) {
  int s, w;

  cin >> s >> w;
  if (w >= s) {
    cout << "unsafe" << endl;
  } else {
    cout << "safe" << endl;
  }
  return 0;
}