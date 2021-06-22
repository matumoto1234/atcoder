#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int count = 0, count2 = 0;
  for (int i = 0; i < n;i++){
    cin >> a[i];
    if(a[i]%4==0){
      count++;
    }else if(a[i]%2==0){
      count2++;
    }
  }
  count2 /= 2;
  n -= count2*2;
  if(count>=n/2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}