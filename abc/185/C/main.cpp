#include<iostream>
#include<vector>
#include<algorithm>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = boost::multiprecision::cpp_int;

ll nCr(ll n,ll r){
  ll res=1;
  for(ll i=1;i<=n-r;i++){
    res*=(n-i+1);
    res/=i;
  }
  return res;
}

int main(){
  ll L;
  cin>>L;
  cout<<nCr(L-1,11LL)<<endl;
  return 0;
}

/* memo */
/*
L-1個の切れ目から11個の切れ目を選ぶ
nCrを使うと
(L-1)C(11)
=(L-1)!/{(11)!*(L-1-11)!}
=(L-1)*(L-2)*...*(L-11)/11!
=(L-1)*(L-2)*...*(L-11)/(11*10*9*...*1)
*/