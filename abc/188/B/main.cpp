#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
using cint = boost::multiprecision::cpp_int;
int main() {
  ll n;
  cin >> n;
  cint sum=0;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  for(int i=0;i<n;i++){
    sum+=a[i]*b[i];
  }
  if(sum==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}