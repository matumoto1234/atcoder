#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(int argc, char* argv[]){
    int h, w;
    cin >> h >> w;

    vector<string> s(h);

    loop(i, h) cin >> s[i];

    loop(i, h){
        loop(j, w){
            if(s[i][j] == '.'){
                int cnt = 0;
                for(int ii = i - 1; ii <= i + 1; ii++){
                    for(int jj = j - 1; jj <= j + 1; jj++){
                        if(ii < 0 || ii >= h || jj < 0 || jj >= w)continue;
                        if(s[ii][jj] == '#'){
                            cnt++;
                        }
                    }
                }
                s[i][j] = cnt + '0';
            }
        }
    }
    loop(i, h){
        cout << s[i] << endl;
    }
    return 0;
}