#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

bool range_check(int h,int w,int y,int x){
  if(y<0||x<0||y>=h||x>=w){
    return false;
  }
  return true;
}

void output(vector<vector<int>>& v){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size();j++){
      if(j){
        cout<<' ';
      }
      cout<<v[i][j];
    }
    cout<<'\n';
  }
  cout<<'\n';
}

bool naname(vector<vector<int>>& v,int y,int x){
  int n=(int)v.size();
  int cnt=1;
  y++;
  x++;
  while(range_check(n,n,y,x)){
    if(v[y-1][x-1]==v[y][x]){
      cnt++;
      if(cnt>=3){
        return true;
      }
    }else{
      cnt=1;
    }
    y++;
    x++;
  }
  return false;
}

bool naname2(vector<vector<int>>& v,int y,int x){
  int n=(int)v.size();
  int cnt=1;
  y--;
  x++;
  while(range_check(n,n,y,x)){
    if(v[y+1][x-1]==v[y][x]){
      cnt++;
      if(cnt>=3){
        return true;
      }
    }else{
      cnt=1;
    }
    y--;
    x++;
  }
  return false;
}

bool is_cont(vector<vector<int>>& v){
  int n=(int)v.size();

  for(int i=0;i<n;i++){
    int cnt=1;
    for(int j=1;j<n;j++){
      if(v[i][j]==v[i][j-1]){
        cnt++;
        if(cnt>=3){
          return true;
        }
      }else{
        cnt=1;
      }
    }
  }

  for(int j=0;j<n;j++){
    int cnt=1;
    for(int i=1;i<n;i++){
      if(v[i][j]==v[i-1][j]){
        cnt++;
        if(cnt>=3){
          return true;
        }
      }else{
        cnt=1;
      }
    }
  }

  for(int i=0;i<n;i++){
    if(naname(v,i,0)){
      return true;
    }
    if(naname(v,0,i)){
      return true;
    }
    if(naname2(v,i,0)){
      return true;
    }
    if(naname2(v,n-1,i)){
      return true;
    }
  }

  
  return false;
}

int main(){
  ll n;
  cin>>n;

  if(n==1||n==2){
    cout<<1<<' '<<1<<endl;
    return 0;
  }
  cout<<2<<' ';
  if(n==3){
    cout<<32<<endl;
    return 0;
  }
  if(n==4){
    cout<<18<<endl;
    return 0;
  }
  cout<<8<<endl;
  return 0;









  /*
  vector<vector<int>> v2(n,vector<int>(n,0));
  ll tate;
  ll cnt=0;
  ll i;
  for(i=0;i<(1<<(n*n));i++){
    for(ll j=0;j<n*n;j++){
      tate=j/n;
      if(i>>j&1){
        v2[tate][j%n]=1;
      }else{
        v2[tate][j%n]=0;
      }
    }

    if (is_cont(v2)==false) {
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
  */
}