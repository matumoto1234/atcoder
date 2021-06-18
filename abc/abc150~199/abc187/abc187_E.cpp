#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200000;

vector<vector<int>> T(MAXN);
vector<int> tour;

void euler_tour(int idx){
  int sz=T[idx].size();
  if(sz==0){
    tour.push_back(idx);
    return;
  }

  tour.push_back(idx);
  for(int to:T[idx]){
    euler_tour(to);
  }
  tour.push_back(idx);
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    T[a].push_back(b);
    T[b].push_back(a);
  }
}