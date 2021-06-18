#include<iostream>
#include<vector>
using namespace std;

struct zahyo{
  int y,x;
};

int main(){
  constexpr int n=100;
  vector<zahyo> point(n);
  for(int i=0;i<n;i++){
    cin>>point[i].y>>point[i].x;
  }
  
  zahyo now;
  now.y=0;
  now.x=0;
  for(int i=0;i<n;i++){

    //yoko
    char order;
    if(point[i].x<now.x){
      order='L';
    }else{
      order='R';
    }
    int len=abs(point[i].x-now.x);
    for(int j=0;j<len;j++){
      cout<<order;
    }

    //tate
    if(point[i].y<now.y){
      order='D';
    }else{
      order='U';
    }
    len=abs(point[i].y-now.y);
    for(int j=0;j<len;j++){
      cout<<order;
    }
  }
  cout<<'\n';
  return 0;
}