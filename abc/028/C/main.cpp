#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(5);
  for(int i=0;i<5;i++){
    cin>>a[i];
  }
  vector<int> sum(32,0);
  for (int j = 0; j < (1 << 5); j++) {
    int counter = 0;
    for (int k = 0; k < 5; k++) {
      if (j >> k & 1) {
        sum[j] += a[k];
        counter++;
      }
    }
    if (counter != 3) {
      sum[j] = 0;
    }
  }
  sort(sum.begin(),sum.end());
  sum.erase(unique(sum.begin(),sum.end()),sum.end());
  sort(sum.rbegin(),sum.rend());
  cout<<sum[2]<<endl;
  return 0;
}