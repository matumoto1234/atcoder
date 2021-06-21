#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct sushi {
  ll x, v;

  sushi(){}
  sushi(ll x,ll v):x(x),v(v){}
  bool operator<(const sushi& o)const{
    return v==o.v ? x<o.x : v<o.v;
  }
};
ostream& operator<<(ostream& os,sushi m){os<<m.v;return os;}

template <typename T>
struct SparseTable {
  vector<vector<T>> st;
  vector<int> lookup;

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= v.size())
      ++b;
    st.assign(b, vector<T>(1 << b));
    for (int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for (int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return max(st[b][l], st[b][r - (1 << b)]);
  }
};

template <typename T>
void debug(const vector<T>& v){
  int n=v.size();
  for(int i=0;i<n;i++){
    if(i) cerr<<' ';
    cerr<<v[i];
  }
  cerr<<"\n";
}

ll n, c;

ll solve(vector<sushi> a) {
  // r[i]:=右回りでi番目に到達したときの値
  vector<sushi> r(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i].v;
    r[i].v = sum - a[i].x;
    r[i].x=a[i].x;
  }

  // l[i]:=左回りでi番目に到達したときの値
  vector<sushi> l(n);
  sum = 0;
  for (int i = n-1; i >= 0; i--) {
    sum += a[i].v;
    l[i].v = sum - (c - a[i].x);
    l[i].x=a[i].x;
  }

  //cerr<<"---left---"<<endl;
  //debug(l);

  //cerr<<"---right---"<<endl;
  //debug(r);

  SparseTable<sushi> r_table(r);
  SparseTable<sushi> l_table(l);

  ll res=0;
  for(int i=0;i<n;i++){
    if(i==n-1) {
      sushi vr=r_table.rmq(0,i+1);
      res=max(vr.v,res);
      continue;
    }
    sushi vr=r_table.rmq(0,i+1);
    sushi vl=l_table.rmq(i+1,n);

    //cerr<<"vr:"<<vr<<" vl:"<<vl<<endl;
    res=max({vr.v-vr.x+vl.v, vr.v, res});
  }
  //cerr<<res<<endl;
  return res;
}

int main() {
  cin >> n >> c;
  vector<sushi> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].v;
  }

  ll v1 = solve(a);
  for (int i = 0; i < n; i++)
    a[i].x = c - a[i].x;
  reverse(a.begin(), a.end());
  ll v2 = solve(a);
  cout << max(v1, v2) << endl;
}