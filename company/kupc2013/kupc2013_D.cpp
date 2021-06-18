#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll sum=1;
  stack<ll> st;
  st.push(a[0]);

  for(ll i=1;i<n;i++){
    if(st.top()>a[i]){
      while (st.top() > a[i]) {
        st.pop();
        if(st.empty()){
          break;
        }
      }
      if(st.empty()){
        sum++;
        st.push(a[i]);
        continue;
      }
    }
    if(st.top()<a[i]){
      st.push(a[i]);
      sum++;
    }
  }
  cout<<sum<<endl;
  return 0;
}