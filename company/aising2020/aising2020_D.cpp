#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string x;
  cin >> n >> x;
  bitset<200000> bit;
  for (int i = 0; i < n;i++){
    if(x[i]=='1'){
      bit[i].set();
    }
  }
  for (int i = 0; i < n;i++){
    bit[i].flip()
  }
}