#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int d, n;
  cin >> d >> n;
  if(d==0){
    if(n==100){
      cout << 101 << endl;
    }else{
      cout << n << endl;
    }
  }
  else if(d==1){
    int sum = 100;
    if(n==100){
      cout << 10100 << endl;
    }else{
      cout << n * 100 << endl;
    }
  }
  else if(d==2){
    if(n==100){
      cout << 1010000 << endl;
    }
    else{
      cout << n * 10000 << endl;
    }
  }
  return 0;
}