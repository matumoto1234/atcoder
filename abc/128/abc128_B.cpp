#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  using P = pair<int,int>;
  vector<pair<string,P>> a(n);
  for(int i=0;i<n;i++){
    string &s = a[i].first;
    int &p = a[i].second.first;
    int &idx = a[i].second.second;
    cin>>s>>p;
    p*=-1;
    idx=i+1;
  }

  sort(a.begin(),a.end());

  for(int i=0;i<n;i++){
    int idx=a[i].second.second;
    cout<<idx<<'\n';
  }
}