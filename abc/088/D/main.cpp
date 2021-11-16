#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct zahyo {
  int y, x;
};

bool range_check(int h, int w, int y, int x) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return false;
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;
  int black_cnt=0;
  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
      if(s[i][j]=='#'){
        black_cnt++;
      }
    }
  }

  vector<vector<int>> arrived(h, vector<int>(w, -1));
  arrived[0][0] = 1;
  queue<zahyo> Q;
  zahyo init;
  init.y = 0;
  init.x = 0;
  Q.push(init);
  int dirY[] = {0, 1, -1, 0};
  int dirX[] = {1, 0, 0, -1};
  while (!Q.empty()) {
    zahyo now = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = now.y+dirY[i];
      int nx = now.x+dirX[i];

      if (range_check(h, w, ny, nx) == false) {
        continue;
      }
      if (s[ny][nx] == '#') {
        continue;
      }
      if (arrived[ny][nx] != -1) {
        continue;
      }

      arrived[ny][nx] = arrived[now.y][now.x] + 1;
      zahyo Next;
      Next.y = ny;
      Next.x = nx;
      Q.push(Next);
    }
  }
  if (arrived[h - 1][w - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }
  cout << h * w - black_cnt - arrived[h - 1][w - 1] << endl;
  return 0;
}