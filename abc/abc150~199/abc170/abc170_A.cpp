#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(5);
  for (int i = 0; i < 5;i++){
    cin >> a[i];
    if(a[i]==0){
      cout << i+1 << endl;
    }
  }
  return 0;
}