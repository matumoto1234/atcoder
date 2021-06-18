#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
  ll p,c,index;
};

bool asc(const node& l,const node& r){
  return l.p==r.p?l.c<r.c:l.p<r.p;
}

int main(){
  ll n,k;
  cin>>n>>k;
  vector<node> a(n);
  for(ll i=0;i<n;i++){
    cin>>a[i].p;
    a[i].index=i+1;
  }
  for(ll i=0;i<n;i++){
    cin>>a[i].c;
  }
  sort(a.begin(),a.end(),asc);
  vector<ll> ruiseki(n+1,0);
  for(ll i=0;i<n;i++){
    //printf("%lld %lld\n",a[i].p,a[i].c);
    ruiseki[i+1]=a[i].c+ruiseki[i];
  }
  return 0;
}