#include<bits/stdc++.h>
using namespace std;

double absd(double x){
  if(x<0.0){
    x *= -1.0;
  }
  return x;
}

int main(){
  double n, sum=0.0, ave;
  int ii;
  double sa;
  cin >> n;
  vector<double> a(n);
  for (int i = 0; i < n;i++){
    cin >> a[i];
    sum += a[i];
  }
  ave = sum / n;
  sa = absd(ave - a[0]);
  ii = 0;
  for (int i = 0; i < n;i++){
    double tmp = absd(ave - a[i]);
    if(sa>tmp){
      sa = tmp;
      ii = i;
    }
  }
  cout << ii << endl;
  return 0;
}