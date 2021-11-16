#include<iostream>
#include<vector>
#include<map>
using namespace std;

class UnionFind{
  public:

  // Parent
  vector<int> par;

  vector<map<int,int>> cnt;

  // Constructor
  UnionFind(int size,vector<int>& v):par(size),cnt(size){
    for(int i=0;i<size;i++){
      par[i]=i;
      cnt[i][v[i]]++;
    }
  }

  //----- Member function -----

  // serach root
  int root(int x){
    if(x==par[x]){
      return x;
    }
    return par[x]=root(par[x]);
  }

  // Merge(Unite, Union)
  bool merge(int x,int y){
    map<int,int> rx=cnt[root(x)],ry=cnt[root(y)];
    if(rx==ry){
      return false;
    }

    // Smaller one merge to bigger one
    if(rx.size()<ry.size()){
      swap(rx,ry);
    }
    for(auto itr=ry.begin();itr!=ry.end();itr++){
      rx[itr->first]+=itr->second;
    }
    par[ry]=rx;
    return true;
  }

  // Judge same or not
  bool isSame(map<int,int> x,map<int,int> y){
    return root(x)==root(y);
  }
};

int main(){
  map<int,int> mp;
  return 0;
}