#include<bits/stdc++.h>
using namespace std;

int s(int x){
  int sum = 0;
  while(x>0){
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main(){
  int n;
  cin >> n;
  if(n%s(n)==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}