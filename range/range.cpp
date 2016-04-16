/*
ID: guangli1
PROG: range
LANG: C++11  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#define LL unsigned long long
#define inf 
#define INF (~(1<<31))
using namespace std;
const int N = 250;
int m[N][N];
int n;
int dp[N][N];
int cnt[N] = {0};

void init(){
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        char s[N]; 
        scanf("%s", s);
        for(int j = 0; j < n; j++){
            //scanf("%d", &m[i][j]);
            m[i][j] = s[j] == '1' ? 1 : 0;
//            cout << m[i][j] ;
        }
    }
}

void run(){
    for(int k = 0; k < 2*n-1; k++)
        for(int i = 0; i < n; i++){
            int j = k - i;
            if(j < 0 || j >= n)
                continue;
            int r1, r2, r3;
            r1 = i-1 < 0 ? 0 : dp[i-1][j]; 
            r2 = j-1 < 0 ? 0 : dp[i][j-1];
            r3 = (i-1 < 0 || j-1 < 0) ? 0 : dp[i-1][j-1];  
            dp[i][j] = m[i][j] ? 1 + min(r1, min(r2, r3)) : 0;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 2; k <= dp[i][j]; k++)
                ++cnt[k];
            
    for(int i = 2; i <= n; i++)
        if(cnt[i])
            cout << i << " " << cnt[i] << endl;
}
int main() {
    freopen("range.out", "w", stdout);
    freopen("range.in", "r", stdin);
    init();
    run();
    return 0;
}
