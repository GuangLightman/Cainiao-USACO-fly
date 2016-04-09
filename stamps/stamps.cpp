/*
ID: guangli1
PROG: stamps
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
const int N = 200*10000;
const int K = 200;
const int NN = 50;
int val[NN];
int k, n;
int kinds[N+5] = {0};

int main() {
    freopen("stamps.out", "w", stdout);
    freopen("stamps.in", "r", stdin);
    scanf("%d %d", &k, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    int start = 1;
    while(true){
        int m = k;
        for(int j = 0; j < n; j++){
            if(start - val[j] >= 0)
               m = min(kinds[start-val[j]], m); 
        }
        if(m <= k-1)
            kinds[start] = m+1;
        else
            break;
        start++;
    }
    return 0;
}
