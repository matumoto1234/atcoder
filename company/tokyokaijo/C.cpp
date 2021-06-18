#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  k=min(41LL,k);
  for(int i=0;i<k;i++){
    vector<int> b(n,0);
    for(int j=0;j<n;j++){
      int l=max(0LL,j-a[j]);
      int r=min(n-1,j+a[j]);
      b[l]++;
      if(r+1<n){
        b[r+1]--;
      }
    }
    a[0]=b[0];
    for(int j=1;j<n;j++){
      b[j]+=b[j-1];
      a[j]=b[j];
    }
    /*
    for (ll x : a) {
      cout << x << " ";
    }
    cout << endl;
    */
  }
  for(ll x:a){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}