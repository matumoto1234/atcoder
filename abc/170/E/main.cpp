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
using Pll = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  const int N=200000;
  int n,q;
  cin>>n>>q;
  vector<P> children(n);
  vector<map<int,int>> sets(N);
  range(i,0,n){
    auto &[a,b]=children[i];
    cin>>a>>b;
    b--;
    sets[b][a]++;
  }

  vector<int> c(q),d(q);
  range(i,0,q){
    cin>>c[i]>>d[i];
    c[i]--;
    d[i]--;
  }

  map<int,int> best;
  range(i,0,N){
    if(sets[i].empty()) continue;
    int key=sets[i].rbegin()->first;
    best[key]++;
  }

  range(i,0,q){
    auto &[rate,old]=children[c[i]];
    if(sets[old].rbegin()->first==rate&&sets[old][rate]==1){
      best[rate]--;
      if(best[rate]==0) best.erase(rate);
      sets[old][rate]--;
      if(sets[old][rate]==0) sets[old].erase(rate);
      if(!sets[old].empty()) best[sets[old].rbegin()->first]++;
    }else{
      sets[old][rate]--;
      if(sets[old][rate]==0) sets[old].erase(rate);
    }


    if(sets[d[i]].empty()){
      best[rate]++;
    }else if(sets[d[i]].rbegin()->first<rate){
      best[sets[d[i]].rbegin()->first]--;
      if(best[sets[d[i]].rbegin()->first]==0){
        best.erase(sets[d[i]].rbegin()->first);
      }
      best[rate]++;
    }
    sets[d[i]][rate]++;
    old=d[i];
//    cerr<<"--------begin-------"<<endl;
//    for(auto p:best){
//      cerr<<p<<endl;
//    }
//    cerr<<"--------end-------"<<endl;
//    cerr<<best.begin()->first<<' '<<best.begin()->second<<newl;
    cout<<best.begin()->first<<newl;
  }
}