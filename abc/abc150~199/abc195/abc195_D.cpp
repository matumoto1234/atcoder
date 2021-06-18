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

int n,m,q;
vector<P> bag;
vector<int> box;
int query(int l,int r){
  vector<int> nbox;
  range(i,0,m){
    if(l<=i&&i<=r) continue;
    nbox.emplace_back(box[i]);
  }
  int res=0;
  sort(nbox.begin(),nbox.end());
  vector<bool> used(nbox.size(),false);
  range(i,0,n){
    auto [v,w]=bag[i];

    range(j,0,nbox.size()){
      if(used[j]==false&&w<=nbox[j]){
        used[j]=true;
        //cout<<"v:"<<v<<" w:"<<w<<endl;
        res+=v;
        break;
      }
    }
  }
  return res;
}

int main() {
  cin>>n>>m>>q;
  bag.resize(n);
  range(i,0,n){
    auto &[v,w] = bag[i];
    cin>>w>>v;
  }
  sort(bag.rbegin(),bag.rend());

  box.resize(m);
  range(i,0,m){
    cin>>box[i];
  }

  range(i,0,q){
    int l,r;
    cin>>l>>r;
    l--;
    r--;
    cout<<query(l,r)<<endl;
  }
}