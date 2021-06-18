#include<bits/stdc++.h>
using namespace std;

class UnionFind {
 public:
  // Parent
  vector<int> par;
  // Size
  vector<int> siz;

  // Constructor
  UnionFind(int size) :par(size),siz(size,1){
    for (int i = 0; i < size; i++) {
      par[i]=i;
    }
  }

  // Initialize
  void init(int size) {
    par.resize(size);
    siz.assign(size, 1);
    for (int i = 0; i < size; i++) {
      par[i] = i;
    }
  }

  //----- Member function -----

  // serach root
  int root(int x) {
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  // Union(Unite, Marge)
  bool merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) {
      return false;
    }

    // Smaller one merge to bigger one
    if (siz[rx] < siz[ry]) {
      swap(rx, ry);
    }
    siz[rx] += siz[ry];
    par[ry] = rx;
    return true;
  }

  // Judge same or not
  bool issame(int x, int y) { return root(x) == root(y); }

  // Size of group
  int size(int x) { return siz[root(x)]; }
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  UnionFind tree(n);
  int p,a,b;
  for(int i=0;i<q;i++){
    cin>>p>>a>>b;
    if(p==0){
      tree.merge(a,b);
    }else{
      cout<<(tree.issame(a,b)?"Yes":"No")<<"\n";
    }
  }
  cout<<flush;
  return 0;
}