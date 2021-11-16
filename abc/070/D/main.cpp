#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ki {
  ll num, kyori;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<vector<ki>> node(n);
  for (ll i = 0; i < n - 1; i++) {
    ki temp;
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    temp.num = b;
    temp.kyori = c;
    node[a].push_back(temp);
    temp.num = a;
    temp.kyori = c;
    node[b].push_back(temp);
  }
  ll q, k;
  cin >> q >> k;
  k--;
  // bfs
  queue<ll> que;
  vector<ll> dist(n, 0);
  que.push(k);
  while (!que.empty()) {
    ll temp = que.front();
    que.pop();
    for (ll i = 0; i < node[temp].size(); i++) {
      if (dist[node[temp][i].num] == 0) {
        que.push(node[temp][i].num);
        dist[node[temp][i].num] = dist[temp] + node[temp][i].kyori;
      }
    }
  }

  for (ll i = 0; i < q; i++) {
    ll x, y;
    cin>>x>>y;
    x--;
    y--;
    cout << dist[x] + dist[y] << endl;
  }

  /* 
  for (ll i = 0; i < n; i++) {
    prllf("%d = ", i);
    for (ll j = 0; j < node[i].size(); j++) {
      if (j) {
        prllf(" ");
      }
      prllf("%d", node[i][j]);
    }
    prllf("\n");
  }
  for(ll i=0;i<n;i++){
    cout<<dist[i]<<endl;
  }
  */
  return 0;
}