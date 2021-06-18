#include<bits/stdc++.h>
#include<atcoder/modint.hpp>
using namespace std;
using namespace atcoder;
const int MAXN = 100;
const int MAXK = 100;

int n,k;
string s;
modint two;

char winner(char,char);

vector<vector<char>> dp(MAXN+1,vector<char>(MAXK+1,'N'));
char dfs(modint offset,int k){
  if(k==0) return s[offset.val()];

  char &res=dp[offset.val()][k];
  if(res!='N') return res;

  modint offset2(offset.val()+two.pow(k-1));
  res=winner(dfs(offset,k-1),dfs(offset2,k-1));
  return res;
}

int main(){
  cin>>n>>k>>s;
  modint::set_mod(n);
  two=2;

  cout<<dfs(0,k)<<endl;
}

char winner(char a, char b) {
  switch (a) {
  case 'R':
    switch (b) {
    case 'R':
      return 'R';
    case 'S':
      return 'R';
    case 'P':
      return 'P';
    }
  case 'S':
    switch (b) {
    case 'R':
      return 'R';
    case 'S':
      return 'S';
    case 'P':
      return 'S';
    }
  case 'P':
    switch (b) {
    case 'R':
      return 'P';
    case 'S':
      return 'S';
    case 'P':
      return 'P';
    }
  }
  return 'N';
}