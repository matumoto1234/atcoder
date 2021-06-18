#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NIL = 1e9+1;


class UnionFind{
  public:

  // Parent
  vector<ll> par;
  // Size
  vector<ll> siz;
  // Value
  vector<ll> value;
  // Sum
  vector<ll> sum;

  // Constructor
  UnionFind(ll size):par(size),siz(size),value(size),sum(size){
    for(ll i=0;i<size;i++){
      par[i]=i;
      siz[i]=1;
      sum[i]=0;
    }
  }

  // Initialize
  void init(ll size){
    par.resize(size);
    siz.assign(size,1);
    for(ll i=0;i<size;i++){
      par[i]=i;
    }
  }

  //----- Member function -----

  // serach root
  ll root(ll x){
    if(x==par[x]){
      return x;
    }
    par[x]=root(par[x]);
    return par[x];
  }

  void sumsum(ll x){
    sum[root(x)]+=value[x];
    sum[x]=sum[root(x)];
    //printf("sum[%lld]=%lld\n",x,sum[x]);
    //printf("root:sum[%lld]=%lld\n",root(x),sum[root(x)]);
  }

  // Union(Unite, Marge)
  bool merge(ll x,ll y){
    ll rx=root(x);
    ll ry=root(y);
    if(rx==ry){
      return false;
    }

    // Smaller one merge to bigger one
    if(siz[rx]<siz[ry]){
      swap(rx,ry);
    }
    siz[rx]+=siz[ry];
    par[ry]=rx;
    return true;
  }

  // Judge same or not
  bool isSame(ll x,ll y){
    return root(x)==root(y);
  }

  // Size of group
  ll size(ll x){
    return siz[root(x)];
  }
};

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> a(n),b(n);
  UnionFind tree1(n);
  UnionFind tree2(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    tree1.value[i]=a[i];
    tree1.sum[i]=0;
  }
  for(ll i=0;i<n;i++){
    cin>>b[i];
    tree2.value[i]=b[i];
    tree2.sum[i]=0;
  }
  for(ll i=0;i<m;i++){
    ll c,d;
    cin>>c>>d;
    c--;
    d--;
    tree1.merge(c,d);
    tree2.merge(c,d);
  }

  for(int i=0;i<n;i++){
    tree1.sumsum(i);
    tree2.sumsum(i);
  }

  bool flg=true;
  for(int i=0;i<n;i++){
    if(tree1.sum[tree1.root(i)]!=tree2.sum[tree2.root(i)]){
      flg=false;
      break;
    }
  }
  cout<<(flg?"Yes":"No")<<endl;
  return 0;
}