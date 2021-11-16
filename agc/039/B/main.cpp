#include<bits/stdc++.h>
using namespace std;

vector<int> make_v(int a,int n){
  vector<int> res;
  int m=a;
  while(m<n){
    res.push_back(m);
    m*=a;
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  vector<int> six = make_v(6,n);
  vector<int> nine = make_v(9,n);
  
}