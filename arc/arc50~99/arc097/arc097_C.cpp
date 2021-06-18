#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int k;
  cin >> s >> k;

  string max_s(5000, 'z');

  vector<string> box(100, max_s);
  for (int boxi = 0; boxi < k; boxi++) {
    for (int i = 0; i < s.size(); i++) {
      for (int j = 1; j <= k; j++) {
        string temp = s.substr(i, j);
        bool flg = true;
        for (int index = 0; index < boxi; index++) {
          if (box[index] == temp) {
            flg = false;
            break;
          }
        }
        if (flg && box[boxi] > temp) {
          box[boxi] = temp;
        }
      }
    }
  }
  cout<<box[k-1]<<endl;
  return 0;
}