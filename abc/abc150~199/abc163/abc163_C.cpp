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
    int n;
    int a[200000];
    int list[200000];

    cin>>n;

    for(int i=0;i<200000;i++)list[i]=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        list[a[i]-1]++;
    }
    for(int i=0;i<n;i++){
        cout<<list[i]<<endl;
    }
    return 0;
}