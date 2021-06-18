#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

ll h,w;
bool rangeCheck(ll y,ll x){
  if(y<0||x<0||y>=h||x>=w){
    return true;
  }
  return false;
}

ll loop(vector<vector<bool>> s,vector<bool> muki,ll n){
  cout<<"hello"<<endl;
  if(n==-1){
    return 0LL;
  }

  ll res=0;
  for(ll i=0;i<h;i++){
    for(ll j=0;j<w;j++){
      if(s[i][j]){
        continue;
      }
      if(muki[n]){
        if(rangeCheck(i+1,j)==false){
          continue;
        }
        s[i][j]=true;
        s[i+1][j]=true;
        res++;
      }else{
        if(rangeCheck(i,j+1)==false){
          continue;
        }
        s[i][j]=true;
        s[i][j+1]=true;
        res++;
      }
      res=loop(s,muki,n-1);
      res%=p;
    }
  }
  return res;
}

int main(){
  ll n;
  cin>>h>>w>>n;
  n--;
  
  vector<vector<bool>> s(h,vector<bool>(w,false));
  vector<bool> muki(n,true);
  // tatemuki:true,,,,yokomuki:false
  ll ans=0;
  for(ll i=n;i>=0;i--){
    ans+=loop(s,muki,n);
    muki[i]=false;
  }
  cout<<ans%p<<endl;
  return 0;
}
