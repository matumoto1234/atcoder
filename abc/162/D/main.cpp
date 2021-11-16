#include<iostream>

using namespace std;

int main(int argc,char *argv[]){
    int n;
    char s[4001];
    int r,g,b,sum;

    r=g=b=0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        switch(s[i]){
            case 'R':
                r++;
                break;
            case 'G':
                g++;
                break;
            case 'B':
                b++;
                break;
            default:
                break;
        }
    }
    sum=r*g*b;
    //cout<<sum<<endl;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<=(n+i-1)/2;j++){
            if(s[i]!=s[j]&&s[i]!=s[j+j-i]&&s[j]!=s[j+j-i]){
                sum--;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}