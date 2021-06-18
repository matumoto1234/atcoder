#include <bits/stdc++.h>
using namespace std;

vector<int> nextY = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> nextX = {-1, 0, 1, -1, 1, -1, 0, 1};
int cnt = 0;
char now;
int max_len = -1;
int cur;

int saiki(vector<string> a, int y, int x) {
  if (y < 0 || x < 0 || y >= 19 || x >= 19 || cur >= 8) {
    // cout << "bbbbb" << endl;
    cur++;
    int ret = cnt;
    cnt = 1;
    return ret;
  }
  // cout << cnt << " " << y << " " << x << " " << cur << endl;
  if (a[y][x] != now) {
    // cout << "aaaaa" << endl;
    cur++;
    int ret = cnt;
    cnt = 1;
    return ret;
  }
  cnt++;
  int tmp;
  for (int i = 0; i < 8; i++) {
    tmp = saiki(a, y + nextY[cur], x + nextX[cur]);
    if (tmp > max_len) {
      max_len = tmp;
    }
  }
  return max_len;
}

int main() {
  vector<string> b(19);
  for (int i = 0; i < 19; i++) {
    cin >> b[i];
  }
  int bc = 0;
  int wc = 0;
  int bmax = -1;
  int wmax = -1;
  int bmax_tmp, wmax_tmp;
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      max_len = -1;
      cnt = cur = 0;
      bmax_tmp = wmax_tmp = 0;
      if (b[i][j] == 'o') {
        now = 'o';
        bmax_tmp = saiki(b, i, j);
        bmax = max(bmax, bmax_tmp);
        bc++;
      } else if (b[i][j] == 'x') {
        now = 'x';
        wmax_tmp = saiki(b, i, j);
        wmax = max(wmax, wmax_tmp);
        wc++;
      }
    }
  }
  // cout << wmax << endl << bmax << endl << bc << endl << wc << endl;
  if (abs(wc - bc) > 1) {
    cout << "NO" << endl;
  } else if (wmax < 5 && bmax < 5) {
    if (wc > bc) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  } else if (wmax >= 5 && bmax >= 5) {
    cout << "NO" << endl;
  } else if (wmax >= 5) {
    if (wmax >= 10) {
      cout << "NO" << endl;
    } else {
      if (wc > bc || bc > wc) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  } else {
    if (bmax >= 10) {
      cout << "NO" << endl;
    } else {
      if (bc <= wc) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}