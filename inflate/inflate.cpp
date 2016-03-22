/*
ID: guangli1
PROG: inflate
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
const int M = 10000;
const int N = 10000;
int m, n;
int tm[N];
int score[N];
int dp[M+1];
int visited[M+1];
void intial(){
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        scanf("%d %d", &score[i], &tm[i]);
}
int cal(int t){
    if(t < 0) return 0;
    if(visited[t]) return dp[t];
    dp[t] = 0;
    for(int i = 0; i < n; i++)
        if(t >= tm[i])
            dp[t] = max(dp[t], cal(t-tm[i]) + score[i]); 
    visited[t] = 1;
    return dp[t];
}
void run(){
    cout << cal(m) << endl;
}
int main() {
    freopen("inflate.out", "w", stdout);
    freopen("inflate.in", "r", stdin);
    intial();
    run();
    return 0;
}
