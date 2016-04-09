/*
ID: guangli1
PROG: ratios
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
#define any 1000000
using namespace std;
int a[4][3];
int check(int i, int j, int k){
    int d[3];
    for(int p = 0; p < 3; p++)
       d[p] = i*a[1][p] + j*a[2][p] + k*a[3][p];
    int ratio = any;
    bool flag = false;
    for(int p = 0; p < 3; p++)
        if(a[0][p]){
            ratio = d[p]/a[0][p]; 
            flag = true;
        }
    if(flag == false) return -1; 
    flag = true;
    for(int p = 0; p < 3; p++){
        if(ratio * a[0][p] != d[p]){
             flag = false;
             break;
         }
    }     
    if(flag)
        return ratio;
    else 
        return -1;
}
int main() {
    freopen("ratios.out", "w", stdout);
    freopen("ratios.in", "r", stdin);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    for(int sum = 1; sum <= 300; sum++)
        for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++){
                int k = sum - i - j;
                int res;
                if(i <= sum && j <= sum && k >= 0 && -1 != (res = check(i, j, k))){
                    printf("%d %d %d %d\n", i, j, k, res);
                    return 0;
                }
            }
    printf("NONE\n"); 
    return 0;
}
