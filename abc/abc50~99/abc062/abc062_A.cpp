#include<bits/stdc++.h>
using namespace std;

int check(int x){
  if (x == 2) {
    return 2;
  } else if (x == 4 || x == 6 || x == 9 || x == 11) {
    return 1;
  }
  return 0;
}

int main(){
  int x, y;
  int flgx = 0, flgy = 0;
  cin >> x >> y;
  if(check(x)==check(y)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}