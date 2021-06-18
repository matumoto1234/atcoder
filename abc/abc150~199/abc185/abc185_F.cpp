#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int ti = 0;

// 1-indexed
vector<int> dat;
int n;

void init(int n_){
  n=1;
  while(n<n_) n*=2;

  dat.assign(2*n,ti);
}

void set_val(int k,int x){
  k+=n;
  dat[k]^=x;
  k/=2;
  while(k>0){
    int l=2*k;
    int r=2*k+1;
    dat[k]=dat[l]^dat[r];
    k/=2;
  }
}

// [a,[l,r),b)
// [l,r)[a,b)[l,r)
// lとrを動かす
int query(int a,int b,int k,int l,int r){
  //cerr<<"a:"<<a<<" b:"<<b<<" k:"<<k<<" l:"<<l<<" r:"<<r<<endl;
  if(r<=a||b<=l) return ti;
  if(a<=l&&r<=b) return dat[k];

  int v1=query(a,b,2*k,l,(l+r)/2);
  int v2=query(a,b,2*k+1,(l+r)/2,r);
  return v1^v2;
}

void build(const vector<int>& v){
  int n_=v.size();
  init(n_);
  for(int i=0;i<n_;i++){
    dat[i+n]=v[i];
  }

  for(int i=n-1;i>0;i--){
    dat[i]=dat[i*2]^dat[i*2+1];
    //cerr<<"dat["<<i<<"]:"<<dat[i]<<' ';
  }
  //cerr<<endl;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int q;
  cin>>n>>q;
  int cpn=n;
  init(n);
  vector<int> a(cpn);
  for(int i=0;i<cpn;i++){
    cin>>a[i];
  }
  build(a);
  for(int i=0;i<q;i++){
    int t,x,y;
    cin>>t>>x>>y;
    if(t==1){
      set_val(x-1,y);
      continue;
    }
    cout<<query(x,y+1,1,1,n+1)<<'\n';
  }
  return 0;
}