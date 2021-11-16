#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>

typedef long long int lli;
using namespace std;

void yespr(){cout<<"Yes\n"<<endl;}
void nopr(){cout<<"No\n"<<endl;}

int main(void){
    int n,m;
    int a[100000];

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
        n-=a[i];
    }
    if(n<0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<n<<endl;
    }
    return 0;
}