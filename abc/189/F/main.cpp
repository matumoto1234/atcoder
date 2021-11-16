#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Matrix{
  vector<vector<ll>> M;
  Matrix(int H,int W):M(H,vector<ll>(W,0)){}
  Matrix(int H,int W,ll init):M(H,vector<ll>(W,init)){}

  void assign(int H,int W,ll init) { M.assign(H,vector<ll>(W,init)); }

  void build_E(){
    int h=M.size();
    int w=M[0].size();
    assign(h,w,0);
    for(int i=0;i<h&&i<w;i++){
      M[i][i]=1;
    }
  }

  // note:for 2D
  void build_rotR(){
    int h=M.size();
    int w=M[0].size();
    assign(h,w,0);
    M[0][0]=0;
    M[0][1]=1;
    M[1][0]=-1;
    M[1][1]=0;
  }

  // note:for 2D
  void build_rotL(){
    int h=M.size();
    int w=M[0].size();
    assign(h,w,0);
    M[0][0]=0;
    M[0][1]=-1;
    M[1][0]=1;
    M[1][1]=0;
  }

  Matrix operator*(Matrix a){
    int h1=M.size();
    int w1=M[0].size();
    int w2=a.M[0].size();
    Matrix res(h1,w2);
    for(int i=0;i<h1;i++){
      for(int j=0;j<w2;j++){
        for(int k=0;k<w1;k++){
          res[i][j]+=M[i][k]*a[k][j];
        }
      }
    }
    return res;
  }

  vector<ll>& operator[](int i){ return M[i]; }
};

int main(){
  int n;
  cin>>n;
  vector<Matrix> ms(n,Matrix(3,1));
  for(auto &m:ms){
    cin>>m[0][0]>>m[1][0];
    m[2][0]=1;
  }

  int m;
  cin>>m;
  const Matrix dim3(3,3,0);
  vector<Matrix> accum_m(m+1,dim3);
  accum_m[0].build_E();

  Matrix rotL(dim3);
  rotL.build_rotL();
  rotL[2][2]=1;

  Matrix rotR(dim3);
  rotR.build_rotR();
  rotR[2][2]=1;

  Matrix mx(dim3);
  mx.build_E();
  mx[0][0]=-1;

  Matrix my(dim3);
  my.build_E();
  my[1][1]=-1;

  for(int i=0;i<m;i++){
    int op,p;
    cin>>op;
    switch(op){
    case 1:
      accum_m[i+1]=rotR*accum_m[i];
      break;
    case 2:
      accum_m[i+1]=rotL*accum_m[i];
      break;
    case 3:
      cin>>p;
      mx[0][2]=2*p;
      accum_m[i+1]=mx*accum_m[i];
      break;
    case 4:
      cin>>p;
      my[1][2]=2*p;
      accum_m[i+1]=my*accum_m[i];
      break;
    }
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    ll a,b;
    cin>>a>>b;
    b--;
    Matrix ans=accum_m[a]*ms[b];
    cout<<ans[0][0]<<' '<<ans[1][0]<<'\n';
  }
}