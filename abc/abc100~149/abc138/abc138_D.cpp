#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    int a,b;
}strKi;

typedef struct node{
    int num;
    node* oya;
}strKi2;

/*bool asc(const strKi& left,const strKi& right){
    return left.a==right.a?left.b<right.b:left.a<right.a;
}*/

int main(void){
    int n,q;

    scanf("%d %d",&n,&q);
    vector<strKi> hen(n);
    vector<int> p(q),x(q);
    vector<strKi2> ki(n);

    /*initialize*/
    for(int i=0;i<n;i++){
        ki[i].num=0;
        ki[i].oya=&ki[0];
    }
    /*input*/
    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&hen[i].a,&hen[i].b);

        ki[hen[i].b-1].oya=&ki[hen[i].a-1];

    }
    for(int i=0;i<q;i++) {
        scanf("%d %d",&p[i],&x[i]);
        ki[p[i]-1].num+=x[i];
    }
    //sort(hen.begin(),hen.end(),asc);

    for(int i=1;i<n;i++){
        ki[i].num+=ki[i].oya->num;
    }
    for(int i=0;i<n;i++){
        cout<<ki[i].num<<endl;
    }

    return 0;
}