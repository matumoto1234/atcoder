#include <bits/stdc++.h>
using namespace std;

int main(){
  int R, C;
  cin >> R >> C;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;

  vector<vector<char>> c(R, vector<char>(C));
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      cin >> c[i][j];
    }
  }

  // Breadth First Search
  int dy[] = {0,1,0,-1};
  int dx[] = {1,0,-1,0};

  vector<int> start = {sy, sx};

  deque< vector<int> > que;
  que.emplace_back(start);

  vector<vector<int>> cnt(R, vector<int>(C, -1));
  cnt[sy][sx] = 0;

  while(!que.empty()){

    vector<int> point = que.front();
    que.pop_front();

    int y = point[0];
    int x = point[1];

    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
      if(c[ny][nx] == '#') continue;
      if(cnt[ny][nx] != -1) continue;

      cnt[ny][nx] = cnt[y][x] + 1;

      vector<int> next_point = {ny, nx};
      que.emplace_back(next_point);
    }
  }

  cout << cnt[gy][gx] << endl;
}