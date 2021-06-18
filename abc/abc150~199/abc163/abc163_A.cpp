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

    cin>>n;
    printf("%.6f\n",2.0*(double)n*3.14159265);

    return 0;
}