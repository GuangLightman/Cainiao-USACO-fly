/*
ID: guangli1
PROG: game1
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
const int N = 100;
int a[N];
int pre[N][N] = {0};
int lat[N][N] = {0};
int main() {
    freopen("game1.out", "w", stdout);
    freopen("game1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]); 
    // i j  <-   i+1, j   i, j-1
    for(int k = 0; k < n; k++)
        for(int i = n-1; i >= 0; i--){
            int j = k + i;
            if(j < 0 || j >= n)
                continue;
            if( i == j){
                pre[i][j] = a[i];
                lat[i][j] = 0;
            }
            else{
                pre[i][j] = max(a[i]+lat[i+1][j], a[j]+lat[i][j-1]);
                lat[i][j] = min(pre[i+1][j], pre[i][j-1]); 
            } 
        }
    cout << pre[0][n-1] << " " << lat[0][n-1] << endl;
    return 0;
}
