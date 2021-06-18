#include<bits/stdc++.h>
using namespace std;

void chenge(vector<vector<char>>& s,vector<vector<bool>>& v,int n){
  for(int i=0;i<2;i++){
    if(v[i][n]){
      s[i][n]='#';
    }else{
      s[i][n]='.';
    }
  }
}

bool add_submit(vector<vector<char>>& s,vector<vector<bool>>& v,int n){
  for(int i=0;i<4;i++){
    bitset<2> bit(i);
    v[0].push_back(bit[0]);
    v[1].push_back(bit[1]);
    chenge(s,v,v.size());

    printf("%s\n%s\n",s[0],s[1]);
    fflush(stdout);

    string c;
    cin>>c;
    if(c=="F"){
      return false;
    }

    if(c=="end"){
      return true;
    }

    return add_submit(s,v,n+1);
  }
}


int main(){
  int n;
  cin>>n;

  vector<vector<bool>> bit(2,vector<bool>(2,false));
  vector<vector<char>> s(2,vector<char>(2));

  bool flg=add_submit(s,bit,1);


  return 0;
}