#include <bits/stdc++.h>
using namespace std;
#define range(i, l, r) for (int i = (int)(l); i < (int)(r); (i) += 1)
#define rrange(i, l, r) for (int i = (int)(r)-1; i >= (int)(l); (i) -= 1)
template <typename T1, typename T2> inline void chmax(T1 &a, T2 b) { a = (a > b ? a : b); }
template <typename T1, typename T2> inline void chmin(T1 &a, T2 b) { a = (a < b ? a : b); }
template <typename T1, typename T2> ostream &operator<<(ostream &os,const pair<T1,T2> &p) { os<<p.first<<' '<<p.second; return os;}
template <typename T> ostream &operator<<(ostream &os,const vector<T> &v) { range(i,0,v.size()) {os<<(i?" ":"")<<v[i];} return os;}
using ull = unsigned long long;
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  int n;
  cin>>n;
  double ans=0.0;
  range(i,1,n){
    ans+=(double)n/(double)(n-i);
  }
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
}

// memo
/*
-有名事実-
「確率pの事象の期待値1/p」

----------証明----------
期待値をxとして意味論で式を立てると
x=成功したときの期待値+成功しなかったときの期待値

連結になったときに値などはないので値を考えずにいくと、

成功したときの確率は1なので、
成功したときの期待値は1

成功しなかったときの確率は(1-p)
成功していないとき期待値は(1-p)xと帰着するので

x=1 + (1-p)x
となる。

式変形すると
x=1+x-px
px=1
x=1/p

これより、確率pのときの期待値は1/pとなることがわかった。
----------証明終了----------


----------解法----------
今回の問題ではN頂点の内から1つの頂点を選ぶので1/N
最初の時点では
・1/Nの確率で連結にならない。
・(N-1)/Nの確立で連結になる。
よって連結になる期待値は
N/(N-1)

2つ連結になっている時点では
・2/Nの確率で連結にならない。
・(N-2)/Nの確率で連結になる。
よって連結になる期待値は
N/(N-2)

︙

1~N-1のこれらの総和を出力すればよい

入力例1
N=2
・1/2の確率で連結にならない。
・(1)/2の確率で連結になる。
よって連結になる期待値は
2

入力例2
N=3
・1/3の確率で連結にならない。
・(3-1)/3の確率で連結になる。
よって連結になる期待値は
3/2

・2/3の確率で連結にならない。
・(3-2)/3の確率で連結になる。
よって連結になる期待値は
3

3 + 3/2で4.5
*/