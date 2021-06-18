#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  if(a+b-c<0){
    if ((a + b - c) * (a + b - c) > 4LL * a * b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
  
  /*√a+√b<√c
  =(√a+√b)^2<c
  =a+2√ab+b<c
  =a+b-c<-2√ab
  =(a+b-c)^2>4ab
  */
  return 0;
}